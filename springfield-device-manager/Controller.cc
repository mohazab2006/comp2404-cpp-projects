
#include "Controller.h"
#include "View.h"
#include <fstream>
#include <limits>
#include <vector>

void Controller::launch(){
    cout<<"Launching..."<<endl;
    initWithTalks();
    cout<<"Done initializing"<<endl;
    int choice = -1;

    // This is what the View shows:
    // cout << "What would you like to do?"<< endl;
    // cout << "  (1) Show all Conferences" << endl;
    // cout << "  (2) Show single Conference" << endl;
    // cout << "  (3) Get talk by speaker" << endl;
    // cout << "  (4) Get talk by keyword" << endl;
    // cout << "  (5) Get talk by speaker or keyword" << endl;
    // cout << "  (6) Print current talk list" << endl;
    // cout << "  (7) Play current talk list" << endl;
    // cout << "  (8) Toggle video" << endl;
    // cout << "  (0) Exit" << endl<<endl;

    while (true){
        choice = -1;
        vector<string> menu ={
            "Show all Conferences",
            "Show single Conference",
            "Get talk by speaker",
            "Get talk by keyword",
            "Get talk by speaker or keyword",
            "Print current talk list",
            "Play current talk list",
            "Toggle video"
        };
        view.menu(menu, choice);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
        if (choice == 0)break;
        switch (choice)
        {
            case 1: showAllConferences(); break;
            case 2: showSingleConference(); break;
            case 3: getTalkBySpeaker(); break;
            case 4: getTalkByKeyword(); break;
            case 5: getTalkBySpeakerAndKeyword(); break;
            case 6: printCurrentTalks(); break;
            case 7: playCurrentTalks(); break;
            case 8: toggleVideo(); break;
        }
        
    }

    cout << "Good-bye!"<<endl;
}


void Controller::initWithTalks(){
    
    cout<<"Initializing conferences..."<<endl;
    for (int i = 0; i < conferences.size(); ++i){
        summitstream.addConference(new Conference(conferences[i], descriptions[i]));
    }

    // add the talks from the file
    ifstream podFile;
    podFile.open("media/media2.txt");
    string conference, title, speaker, keywords;
    string audio, video;

    /*
    * Should read, line by line, the following format:
    * Conference title
    * Talk title
    * Speaker
    * keywords (comma separated)
    * audio content
    * video filename
    */

    /*Speakers
    Joe Smith

    Jane Doe

    Bruce Wayne

    Darth Vader

    Ada Lovelace

    Khan

    Grace Hopper

    Alan Turing
    
    */

    /* Keywords:
        C++, memory management, allocators, AI, machine learning, deep learning, robotics, performance optimization, profiling, concurrency
    */
    
    while( true ){
        if(!getline(podFile, conference))break;
        cout<<"Talk for conference \""<<conference<<"\""<<endl;
        getline(podFile, title);
        getline(podFile, speaker);
        getline(podFile, keywords);
        getline(podFile, audio);
        getline(podFile, video);


        Talk* talk = new Talk(title, speaker, keywords, audio, "videos/"+video);

        if (!summitstream.addTalk(talk, conference)){
            cout<<"***Error adding talk "<<title<<" to conference "<<conference<<endl;
            delete talk;
        }else{
            cout<<"Talk "<<title<<" added successfully!"<<endl;
        }
    }
    podFile.close();
    
}

void Controller::showAllConferences(){
    cout<<"Showing all conferences: "<<endl;
    view.printAllConferences(summitstream.getConferences());
}

void Controller::showSingleConference(){
    int choice = - 1;
    view.conferenceMenu(summitstream.getConferences(), choice);
    Conference* conference = summitstream.getConference(choice);
    view.printConference(conference);
}

void Controller::getTalkBySpeaker(){
    

    string speaker;
    view.promptSpeaker(speaker);
    Search* crit = pf.createSearch("speaker", speaker);
    playlist.clear();
    summitstream.getTalks(*crit, playlist);
    delete crit;
} 
void Controller::getTalkByKeyword(){
    string keyword;
    view.promptKeyword(keyword);
    Search* crit = pf.createSearch("keyword", keyword);
    playlist.clear();
    summitstream.getTalks(*crit, playlist);
    delete crit;
} 
void Controller::getTalkBySpeakerAndKeyword(){
    string speaker, keyword;
    view.promptSpeaker(speaker);
    view.promptKeyword(keyword);
    Search* crit = pf.createSearch("speaker or keyword", speaker, keyword);
    playlist.clear();
    summitstream.getTalks(*crit, playlist);
    delete crit;
} 
void Controller::printCurrentTalks(){
    cout<<"Playlist size: "<<playlist.getSize()<<endl;
    view.printPlaylist(playlist);
} 
void Controller::playCurrentTalks(){
    view.playPlaylist(playlist);
}
void Controller::toggleVideo(){
    view.promptVideo();
}