
#include "TestControl.h"
#include <limits>
#include <vector>
#include <algorithm>
#include "Search.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void TestControl::launch(){

    vector<string> menu ={
        "Test add and print Conferences",
        "Test add and print Talks",
        "Test get Talks by speaker, and test print talks from View class",
        "Test get Talks by keyword",
        "Test get Talks by speaker or keyword",
        //"Test print current talk list",
        "Test play current talk list with video",
        "Test all and get mark"
    };

    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        tester.clearInputBuffer();
        switch(choice){
            case 1: tester.recordMark(1, testAddConferences()); break;
            case 2: tester.recordMark(2, testAddTalks()); break;
            case 3: tester.recordMark(3, testGetTalksBySpeaker()); break;
            case 4: tester.recordMark(4, testGetTalksByKeyword()); break;
            case 5: tester.recordMark(5, testGetTalksBySpeakerAndKeyword()); break;
            // case 6: testPrintCurrentTalkList(); break;
            case 6: tester.recordMark(6, testPlayCurrentTalks()); break;
            case 7: tester.recordMark(7, testAllAndMark(), 22); break;
        }
    }
    std::cout<<"exiting program!!!"<<endl;
}

void TestControl::initConferences(SummitStream& summitstream){
    for (int i = 0; i < conferences.size(); ++i){
        summitstream.addConference(new Conference(conferences[i], descriptions[i]));
    }
}

void TestControl::initWithTalks(SummitStream& summitstream, vector<string>& titleList, vector<string>& speakerList,
                                vector<string>& keywordsList, vector<string>& audioList){

    initConferences(summitstream);

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
            titleList.push_back(title);
            speakerList.push_back(speaker);
            keywordsList.push_back(keywords);
            audioList.push_back(audio);
        }
    }
    podFile.close();
    
}

int TestControl::testAddConferences(){
    cout<<"Testing addConferences()"<<endl;
    SummitStream summitstream;

    initConferences(summitstream);

    cout<<endl<<"Printing all conferences"<<endl<<endl;
    tester.initCapture();
    view.printAllConferences(summitstream.getConferences());
    tester.endCapture();

    int error = 0;
    tester.find(conferences, error);
    if (error>0){
        cout<<"Error: "<<error<<" conferences not found"<<endl;
    }else{
        cout<<"All conference titles found"<<endl;
    }
    tester.find(descriptions, error);
    if (error>0){
        cout<<"Error: "<<error<<" descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found"<<endl;
    }

    int mark = 2 - error;
    if (mark < 0)mark = 0;

    mark += 1; // Your code didn't crash - congrats!

    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
}

int TestControl::testAddTalks(){
    cout<<"Testing addTalks()"<<endl;
    SummitStream summitstream;
    vector<string> speakers;
    vector<string> titles;
    vector<string> keywords;
    vector<string> audio;
    initWithTalks(summitstream, titles, speakers, keywords, audio);

    cout<<endl<<"Printing conferences with talks"<<endl<<endl;
    int errors = 0;
    int index = 0;
    for (int i = 0; i < summitstream.getConferences().getSize(); ++i){
        tester.initCapture();
        summitstream.getConference(i)->printWithTalks(cout);
        tester.endCapture();

        
        vector<string> talks;
        for (int j = 0; j < 5; ++j){
            talks.push_back(titles[5*i+j]);
        }
        int error = 0;
        tester.find(talks, error);
        if (error>0){
            cout<<"Error: "<<error<<" talks not found"<<endl;
        }else{
            cout<<"All talks found for "<<summitstream.getConference(i)->getName()<<endl;
        }
        errors += error;
    }

    int mark = 2 - errors;
    if (mark < 0)mark = 0;
    mark += 1; // Your code didn't crash - congrats!
    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
   
}

int TestControl::testGetTalksBySpeaker(){
    cout<<"Testing get talks by speaker and playPlaylist"<<endl;
    SummitStream summitstream;
    vector<string> speakers;
    vector<string> titles;
    vector<string> keywords;
    vector<string> audio;
    initWithTalks(summitstream, titles, speakers, keywords, audio);

    vector<string> allSpeakers = {"Joe Smith", "Jane Doe", "Bruce Wayne", "Darth Vader", "Ada Lovelace"};


    vector<int> speakersToFind;

    // generate 2 random indices from 0 to numSpeakers
    tester.ran(speakersToFind, 2, allSpeakers.size());

    int errors = 0;

    int mark = 0;

    for (vector<int>::iterator it = speakersToFind.begin(); it != speakersToFind.end(); ++it){
        
        int speaker = *it;
        Search* search = pf.createSearch("speaker", allSpeakers[speaker]);

        vector<string> talksBySpeaker;
        vector<string> missingTalks;
        for (int i = 0; i < titles.size(); ++i){
            if (speakers[i] == allSpeakers[speaker]){
                talksBySpeaker.push_back(titles[i]);
            }else{
                missingTalks.push_back(titles[i]);
            }
        }

        cout<<"Search for talks by speaker "<<allSpeakers[speaker]<<", should find: "<<endl;
        for (string talk: talksBySpeaker){
            cout<<"   "<<talk<<endl;
        }

        // cout<<"Search: "<<*search<<endl;
        List<Talk*> talks;
        summitstream.getTalks(*search, talks);
        delete search;
        cout<<"Printing talks by speaker "<<speakers[speaker]<<endl;
        tester.initCapture();
        view.playPlaylist(talks);
        tester.endCapture();
    
    
        tester.find(talksBySpeaker, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" talks not found"<<endl;
        }else{
            cout<<"All talks found for "<<speakers[speaker]<<endl;
            mark += 1;
        }

        

        tester.confirmAbsent(missingTalks, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" talks found for absent speaker"<<endl;   
        }else{
            cout<<"No talks found for absent speaker"<<endl;
            mark += 1;
        }
        
    }

    mark += 1; // Your code didn't crash - congrats!
    cout<<"Test complete, mark: "<<mark<<"/5"<<endl;
    return mark;
}

int TestControl::testGetTalksByKeyword(){
    cout<<"Testing get talks by keyword - choosing 2 keywords at random"<<endl;
    SummitStream summitstream;
    vector<string> speakers;
    vector<string> titles;
    vector<string> keywords;
    vector<string> audio;
    initWithTalks(summitstream, titles, speakers, keywords, audio);

    cout<<"All keywords: "<<endl;
    for (string k: keywords){
        cout<<"   "<<k<<endl;
    }

    vector<string> allKeywords = {"C++", 
                                  "memory management", 
                                  "allocators", 
                                  "templates", 
                                  "generic programming", 
                                  "concurrency", 
                                  "profiling", 
                                  "performance optimization", 
                                  "AI", 
                                  "machine learning", 
                                  "deep learning", 
                                  "neural networks", 
                                  "systems", 
                                  "garbage collection",
                                  "robotics"};


    vector<int> keywordsToFind;

    // generate 2 random indices from 0 to numSpeakers
    tester.ran(keywordsToFind, 2, allKeywords.size());

    int errors = 0;

    float mark = 0;

    for (int i = 0; i < keywordsToFind.size(); ++i){
        
        int keyword = keywordsToFind[i];
        Search* search = pf.createSearch("keyword", allKeywords[keyword]);

        vector<string> talksByKeyword;
        vector<string> missingTalks;
        for (int i = 0; i < titles.size(); ++i){
            if (keywords[i].find(allKeywords[keyword]) != string::npos){
                talksByKeyword.push_back(titles[i]);
            }else{
                missingTalks.push_back(titles[i]);
            }
        }

        cout<<"Search for talks by keyword "<<allKeywords[keyword]<<", should find: "<<endl;
        for (string talk: talksByKeyword){
            cout<<"   "<<talk<<endl;
        }

        // cout<<"Search: "<<*search<<endl;
        List<Talk*> talks;
        summitstream.getTalks(*search, talks);
        delete search;
        cout<<"Printing talks by keyword \""<<allKeywords[keyword]<<"\""<<endl;
        tester.initCapture();
        view.playPlaylist(talks);
        tester.endCapture();
    
    
        tester.find(talksByKeyword, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" talks not found"<<endl;
        }else{
            cout<<"All talks found for \""<<allKeywords[keyword]<<"\""<<endl;
            mark += 0.5;
        }

        

        tester.confirmAbsent(missingTalks, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" talks found that should not be"<<endl;   
        }else{
            cout<<"No extra talks found"<<endl;
            mark += 0.5;
        }
        
    }

    mark += 1; // Your code didn't crash - congrats!
    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
}

int TestControl::testGetTalksBySpeakerAndKeyword(){
    cout<<"Testing get talks by speaker or keyword - choosing 2 keywords at random"<<endl;
    SummitStream summitstream;
    vector<string> speakers;
    vector<string> titles;
    vector<string> keywords;
    vector<string> audio;
    initWithTalks(summitstream, titles, speakers, keywords, audio);

    cout<<"All keywords: "<<endl;
    for (string k: keywords){
        cout<<"   "<<k<<endl;
    }

    vector<string> allKeywords = {"C++", 
                                  "memory management", 
                                  "allocators", 
                                  "templates", 
                                  "generic programming", 
                                  "concurrency", 
                                  "profiling", 
                                  "performance optimization", 
                                  "AI", 
                                  "machine learning", 
                                  "deep learning", 
                                  "neural networks", 
                                  "systems", 
                                  "garbage collection",
                                  "robotics"};


    vector<int> keywordsToFind;

    // generate 2 random indices from 0 to numSpeakers
    tester.ran(keywordsToFind, 2, allKeywords.size());

    vector<string> allSpeakers = {"Joe Smith", "Jane Doe", "Bruce Wayne", "Darth Vader", "Ada Lovelace"};


    vector<int> speakersToFind;

    // generate 2 random indices from 0 to numSpeakers
    tester.ran(speakersToFind, 2, allSpeakers.size());

    int errors = 0;

    int mark = 0;

    for (int i = 0; i < keywordsToFind.size(); ++i){
        
        int keyword = keywordsToFind[i];
        int speaker = speakersToFind[i];
        Search* search = pf.createSearch("speaker or keyword", allSpeakers[speaker], allKeywords[keyword]);

        vector<string> talksFound;
        vector<string> missingTalks;
        for (int i = 0; i < titles.size(); ++i){
            if (keywords[i].find(allKeywords[keyword]) != string::npos){
                talksFound.push_back(titles[i]);
            }else if (speakers[i] == allSpeakers[speaker]){
                talksFound.push_back(titles[i]);
            }else{
                missingTalks.push_back(titles[i]);
            }
        }

        cout<<"Search for talks by speaker "<<allSpeakers[speaker]<<" or keyword "<<allKeywords[keyword]<<", should find: "<<endl;
        for (string talk: talksFound){
            cout<<"   "<<talk<<endl;
        }

        // cout<<"Search: "<<*search<<endl;
        List<Talk*> talks;
        summitstream.getTalks(*search, talks);
        delete search;
        cout<<"Printing talks by speaker speaker "<<allSpeakers[speaker]<<" or keyword "<<allKeywords[keyword]<<endl;
        tester.initCapture();
        view.playPlaylist(talks);
        tester.endCapture();
    
    
        tester.find(talksFound, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" talks not found"<<endl;
        }else{
            cout<<"All talks found for speaker "<<allSpeakers[speaker]<<" or keyword "<<allKeywords[keyword]<<endl;
            mark += 1;
        }

        

        tester.confirmAbsent(missingTalks, errors);
        if (errors>0){
            cout<<"Error: "<<errors<<" talks found that should not be"<<endl;   
        }else{
            cout<<"No extra talks found"<<endl;
            mark += 1;
        }
        
    }

    mark += 1; // Your code didn't crash - congrats!
    cout<<"Test complete, mark: "<<mark<<"/5"<<endl;
    return mark;
}

int TestControl::testPlayCurrentTalks(){
    vector<string> toFind = {"<( ^.^ )", "[[[[]", "(.)(.)M"
                            };
    cout<<"Testing playPlaylist with video"<<endl;
    SummitStream summitstream;
    vector<string> speakers;
    vector<string> titles;
    vector<string> keywords;
    vector<string> audio;
    initWithTalks(summitstream, titles, speakers, keywords, audio);

    vector<string> allSpeakers = {"Joe Smith", "Jane Doe", "Bruce Wayne", "Darth Vader", "Ada Lovelace"};


    string speaker= "Bruce Wayne";

    
    Search* search = pf.createSearch("speaker", speaker);
    List<Talk*> lessons;
    summitstream.getTalks(*search, lessons);
    delete search;
    for (int i = 0; i < lessons.getSize(); ++i){
        cout<<lessons[i]->getVideoFile()<<endl;
    }
    view.toggleVideo(true);
    cout<<"Playing talks (with video) by speaker "<<speaker<<endl;
    tester.initCapture();
    view.playPlaylist(lessons);
    tester.endCapture();
    view.toggleVideo(false);
    int errors = 0;

    tester.find(toFind, errors);

    if (errors>0){
        cout<<"Error: "<<errors<<" videos not found"<<endl;   
    }else{
        cout<<"Evidence of videos found"<<endl;
    }
    

    

    int mark = 2 - errors;
    if (mark < 0)mark = 0;
    mark += 1; // Your code didn't crash - congrats!

    cout<<"Test complete, mark: "<<mark<<"/3"<<endl;
    return mark;
}

int TestControl::testAllAndMark(){
    int mark = 0;
    mark += testAddConferences();
    mark += testAddTalks();
    mark += testGetTalksBySpeaker();
    mark += testGetTalksByKeyword();
    mark += testGetTalksBySpeakerAndKeyword();
    // mark += testPrintCurrentTalkList();
    mark += testPlayCurrentTalks();
    return mark;
}



