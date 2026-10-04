#include <iostream>
#include <random>
#include <sstream>
#include "HomeShare.h"
#include "Category.h"
#include "Rental.h"
#include "Tester.h"


using namespace std;
using namespace cat;

// unit tests for Reservations and Rentals
int testPrintReservations();
int testPrintRentals();
int testRentalAddReservations();

// Integration tests for HomeShare
int cgTestPrintRentals();
int cgTestPrintReservations();

int main(){
    int choice = -1;
    while(choice != 0 && cin.good()){
        std::cout<<endl;
        std::cout<<" 0. Exit"<<endl;
        std::cout<<" Unit tests for Reservations and Rentals:"<<endl;
        
        std::cout<<" 1. [3 marks] Test print Reservations"<<endl;

        std::cout<<" 2. [3 marks] Test print Rentals"<<endl;
        std::cout<<" 3. [7 marks] Test Rental add, remove, and print Reservations"<<endl;
        std::cout<<endl<<" HomeShare tests:"<<endl;
        std::cout<<" 4. [8 marks] Test add, remove, and print Rentals in HomeShare"<<endl;
        std::cout<<" 5. [9 marks] Test add, remove, and print Reservations in HomeShare"<<endl; 


        std::cout<<" 6. [30 marks] Test all and get mark"<<endl<<endl;
        cin >> choice;
        std::cout<<endl;

        // clear the buffer since buffers are a pain in the butt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice)
        {
            case 1: testPrintReservations(); break;  
            case 2: testPrintRentals(); break;  
            case 3: testRentalAddReservations(); break;
            case 4: cgTestPrintRentals(); break;
            case 5: cgTestPrintReservations(); break;
            case 6: 
                int score = 0;
                score += testPrintReservations();
                score += testPrintRentals();
                score += testRentalAddReservations();
                score += cgTestPrintRentals();
                score += cgTestPrintReservations();
                std::cout << "Your score is "<<score<<" out of 30" << endl << endl;
                break;
        }
    }
    std::cout<<"Bye!"<<endl;
    return 0;  
}


Tester tester;


int testPrintReservations(){
    Reservation reservations[5];

    Tester tester;

    string names[5] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    int num_people[5] = {1, 2, 3, 4, 5};
    Date check_ins[5] = {Date(2024, 1, 1), Date(2024, 2, 2), Date(2024, 3, 3), Date(2024, 4, 4), Date(2024, 5, 5)};
    Date check_outs[5] = {Date(2024, 1, 2), Date(2024, 2, 3), Date(2024, 3, 4), Date(2024, 4, 5), Date(2024, 5, 6)};

    string checkins[5];
    string checkouts[5];

    // Convert the dates to strings and make reservations
    cout<<"Making reservations"<<endl;
    for (int i = 0; i < 5; i++){
        tester.initCapture();
        check_ins[i].print();
        checkins[i] = tester.getOutput();
        tester.endCapture();
        tester.initCapture();
        check_outs[i].print();
        checkouts[i] = tester.getOutput();
        tester.endCapture();
        cout<<"Making reservation "<<i<<endl;
        reservations[i] = Reservation(names[i], num_people[i], check_ins[i], check_outs[i]);
    }

    cout<<"Testing Print Reservation class"<<endl<<endl;
    
    tester.initCapture();
    for (int i = 0; i < 5; i++){
        reservations[i].print();
    }
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({0,1,2,3,4}, names, error);
    if(error > 0){
        cout<<"Error: Some names not found"<<endl;
    }else{
        cout<<"All names found, 1 point earned"<<endl;
        ++score;
    }


    tester.find({0,1,2,3,4}, checkins, error);
    if(error > 0){
        cout<<"Error: Some checkins not found"<<endl;
    }else{
        cout<<"All checkins found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, checkouts, error);
    if(error > 0){
        cout<<"Error: Some checkouts not found"<<endl;
    }else{
        cout<<"All checkouts found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/3"<<endl<<endl;
    return score;
}

int testPrintRentals(){
    Rental rentals[5];

    int rental_id[5] = {1, 2, 3, 4, 5};
    Category categories[5] = {apartment, condo, bungalow, townhouse, misc};
    string categoriesStr[5] = {"apartment", "condo", "bungalow", "townhouse", "misc"};
    string descriptions[5] = {"waterfront", "downtown", "countryside", "close to beach", "embedded in the culture of downtown"};
    int maxPeople[5] = {1, 2, 3, 4, 5};
    double prices[5] = {100, 200, 300, 400, 500};
    string pricesStr[5] = {"$100.00", "$200.00", "$300.00", "$400.00", "$500.00"};

    cout<<"Making rentals"<<endl;
    for (int i = 0; i < 5; i++){
        rentals[i] = Rental(rental_id[i], categories[i], descriptions[i], maxPeople[i], prices[i]);
    }

    cout<<"Testing Print Rental class"<<endl<<endl;

    tester.initCapture();
    for (int i = 0; i < 5; i++){
        rentals[i].print();
    }
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({0,1,2,3,4}, categoriesStr, error);
    if(error > 0){
        cout<<"Error: Some categories not found"<<endl;
    }else{
        cout<<"All categories found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, descriptions, error);
    if(error > 0){
        cout<<"Error: Some descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found, 1 point earned"<<endl;
        ++score;
    }


    tester.find({0,1,2,3,4}, pricesStr, error);
    if(error > 0){
        cout<<"Error: Some prices not found"<<endl;
    }else{
        cout<<"All prices found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/3"<<endl<<endl;
    return score;
}

int testRentalAddReservations(){
    cout<<"test Rental add, remove, and print Reservations"<<endl;
    Rental rental(1, apartment, "Lakeside", 5, 100);

    string names[5] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    string plates[5] = {"AAA", "BBB", "CCC", "DDD", "EEE"};
    int num_people[5] = {1, 2, 3, 4, 5};
    // The third reservation should not be added as it overlaps with the second
    // Order should be 3,4,1,0
    Date check_ins[5] = {Date(2024, 4, 2), Date(2024, 4, 1), Date(2024, 4, 2), Date(2024, 2, 4), Date(2024, 3, 5)};
    Date check_outs[5] = {Date(2024, 4, 3), Date(2024, 4, 2), Date(2024, 4, 4), Date(2024, 2, 5), Date(2024, 3, 6)};

    cout<<"Adding reservations"<<endl;
    for (int i = 0; i < 5; i++){
        cout<<"Adding reservation "<<i<<endl;
        rental.addReservation(names[i], num_people[i], check_ins[i], check_outs[i]);
    }

    cout<<"Testing Print Rental class"<<endl<<endl;

    tester.initCapture();
    rental.printReservations();
    tester.endCapture();

    int score = 0;
    int error = 0;

    tester.find({3,4,1,0}, names, error);
    if(error > 0){
        cout<<"Error: Some names not found"<<endl;
        // return score;
    }else{
        cout<<"All names found, 1 point earned"<<endl;
        ++score;
    }

    tester.findInOrder({3,4,1,0}, names, error);
    if(error > 0){
        cout<<"Error: Some names not found or not in order"<<endl;
        // return score;
    }else{
        cout<<"All names found and in order, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({2}, names, error);
    if(error > 0){
        cout<<"Error: Reservation 2 found but should not be"<<endl;
        // return score;
    }else{
        cout<<"Reservation 2 not found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Printing reservation on date: ";
    check_ins[4].print();
    tester.initCapture();
    rental.printReservation(check_ins[4]);
    tester.endCapture();

    tester.find({4}, names, error);
    if(error > 0){
        cout<<"Error: "<<names[4]<<" not found"<<endl;
    }else{
        cout<<names[4]<<" found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0,1,3}, names, error);
    if(error > 0){
        cout<<"Error: Wrong reservations printed"<<endl;
    }else{
        cout<<"No wrong reservations printed, 1 point earned"<<endl;
        ++score;
    }

    rental.removeReservation(names[4], check_ins[4]);

    cout<<"Printing reservations after removing "<<names[4]<<endl;
    tester.initCapture();
    rental.printReservations();
    tester.endCapture();

    tester.find({3,1,0}, names, error);
    if(error > 0){
        cout<<"Error: Some names not found"<<endl;
    }else{
        cout<<"All names found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({4}, names, error);
    if(error > 0){
        cout<<"Error: Reservation "<<names[4]<<" found but was removed"<<endl;
    }else{
        cout<<"Reservation "<<names[4]<<" not found, 1 point earned"<<endl;
        ++score;
    }



    cout<<"Points earned: "<<score<<"/7"<<endl<<endl;
    return score;

}


int cgTestPrintRentals(){
    HomeShare homeshare;
    // Rental rentals[5];

    int rental_id[5] = {1, 2, 3, 4, 1};
    Category categories[5] = {apartment, condo, bungalow, townhouse, misc};
    string categoriesStr[5] = {"apartment", "condo", "bungalow", "townhouse", "misc"};
    string descriptions[5] = {"waterfront", "downtown", "countryside", "close to beach", "embedded in the culture of downtown"};
    int maxPeople[5] = {1, 2, 3, 4, 5};
    double prices[5] = {100, 200, 300, 400, 500};
    string pricesStr[5] = {"$100.00", "$200.00", "$300.00", "$400.00", "$500.00"};

    cout<<"Making rentals"<<endl;
    for (int i = 0; i < 5; i++){
        cout<<"Adding rental "<<i<<endl;
        homeshare.addRental(rental_id[i], categories[i], descriptions[i], maxPeople[i], prices[i]);
    }

    cout<<"Testing Print Rentals from HomeShare"<<endl<<endl;

    tester.initCapture();
    homeshare.printRentals();
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({0,1,2,3}, categoriesStr, error);
    if(error > 0){
        cout<<"Error: Some categories not found"<<endl;
    }else{
        cout<<"All categories found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3}, descriptions, error);
    if(error > 0){
        cout<<"Error: Some descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found, 1 point earned"<<endl;
        ++score;
    }


    tester.find({0,1,2,3}, pricesStr, error);
    if(error > 0){
        cout<<"Error: Some prices not found"<<endl;
    }else{
        cout<<"All prices found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({4}, categoriesStr, error);

    if(error > 0){
        cout<<"Error: Duplicate rental number 1 found"<<endl;
    }else{
        cout<<"No duplicate rental found, 1 point earned"<<endl;
        ++score;
    }

    cout<<endl<<"Testing print rentals by category"<<endl;
    tester.initCapture();
    homeshare.printRentalsByCategory(apartment);
    tester.endCapture();

    tester.find({0}, categoriesStr, error);
    if(error > 0){
        cout<<"Error: Category apartment not found"<<endl;
    }else{
        cout<<"Category apartment found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({1,2,3,4}, categoriesStr, error);
    if(error > 0){
        cout<<"Error: incorrect Rental categories found"<<endl;
    }else{
        cout<<"No incorrect categories found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Removing rental 1"<<endl;
    homeshare.removeRental(1);

    cout<<"Printing rentals after removing rental 1"<<endl;
    tester.initCapture();
    homeshare.printRentals();
    tester.endCapture();

    tester.find({1,2,3}, categoriesStr, error);
    if(error > 0){
        cout<<"Error: Some categories not found"<<endl;
    }else{
        cout<<"All categories found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0,4}, categoriesStr, error);
    if(error > 0){
        cout<<"Error: Rental 0 or 4 found but should not be"<<endl;
    }else{
        cout<<"No extra rental found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/8"<<endl<<endl;
    return score;
}

int cgTestPrintReservations(){
    HomeShare homeshare;
    cout<<endl<<"homeshare testPrintReservations"<<endl;

    homeshare.addRental(1, apartment, "beachfront", 5, 100);
    homeshare.addRental(2, condo, "downtown", 5, 200);
    homeshare.addRental(3, bungalow, "cute neighbourhood", 5, 300);

    string names[5] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    int num_people[5] = {1, 2, 3, 4, 5};
    // The third reservation should not be added as it overlaps with the first
    // Order should be 3,4,1,0
    Date check_ins[5] = {Date(2024, 4, 2), Date(2024, 4, 1), Date(2024, 4, 2), Date(2024, 2, 4), Date(2024, 3, 5)};
    Date check_outs[5] = {Date(2024, 4, 3), Date(2024, 4, 2), Date(2024, 4, 4), Date(2024, 2, 5), Date(2024, 3, 6)};

    cout<<"Adding reservations"<<endl;
    for (int i = 0; i < 3; i++){
        cout<<"Adding reservation "<<i<<endl;
        homeshare.addReservation(1, names[i], num_people[i], check_ins[i], check_outs[i]);
    }

    homeshare.addReservation(2, names[2], num_people[2], check_ins[2], check_outs[2]);
    homeshare.addReservation(2, names[3],  num_people[3], check_ins[3], check_outs[3]);

    // rental does not exist
    homeshare.addReservation(5, names[4],  num_people[4], check_ins[4], check_outs[4]);

    cout<<"Testing Print Rental class"<<endl<<endl;

    cout<<"Printing rental 1"<<endl;
    tester.initCapture();
    homeshare.printReservations(1);
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.findInOrder({1,0}, names, error);
    if(error > 0){
        cout<<"Error: Some names not found or not in order"<<endl;
    }else{
        cout<<"All names found and in order, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({2,3,4}, names, error);
    if(error > 0){
        cout<<"Error: Reservation found but should not be"<<endl;
    }else{
        cout<<"No extra reservations found, 1 point earned"<<endl;
        ++score;
    }

    cout<<endl<<"*Printing rental 2"<<endl;
    tester.initCapture();
    homeshare.printReservations(2);
    tester.endCapture();

    tester.findInOrder({3,2}, names, error);
    if(error > 0){
        cout<<"Error: Some names not found or not in order"<<endl;
    }else{
        cout<<"All names found and in order, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0,1,4}, names, error);
    if(error > 0){
        cout<<"Error: Reservation found but should not be"<<endl;
    }else{
        cout<<"No extra reservations found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Removing reservation "<<names[3]<<" from rental 2"<<endl;
    homeshare.removeReservation(2, names[3], check_ins[3]);

    cout<<endl<<"*Printing rental 2 after removing "<<names[3]<<endl;
    tester.initCapture();
    homeshare.printReservations(2);
    tester.endCapture();

    tester.find({2}, names, error);
    if(error > 0){
        cout<<"Error: Reservation "<<names[2]<<" not found"<<endl;
    }else{
        cout<<names[2]<<" found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({3}, names, error);
    if(error > 0){
        cout<<"Error: Reservation "<<names[3]<<" found but was removed"<<endl;
    }else{
        cout<<"Reservation "<<names[3]<<" not found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Printing from rental that does not exist"<<endl;
    tester.initCapture();
    homeshare.printReservations(5);
    tester.endCapture();

    tester.confirmAbsent({0,1,2,3,4}, names, error);
    if(error > 0){
        cout<<"Error: Reservation found but should not be"<<endl;
    }else{
        cout<<"No extra reservations found, 1 point earned"<<endl;
        ++score;
    }


    cout<<"Printing reservation on date: ";
    check_ins[2].print();
    tester.initCapture();
    homeshare.printReservations(check_ins[2]);
    tester.endCapture();

    tester.find({0,2}, names, error);
    if(error > 0){
        cout<<"Error: some names not found"<<endl;
    }else{
        cout<<"All names found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({1,3,4}, names, error);
    if(error > 0){
        cout<<"Error: Wrong reservations printed"<<endl;
    }else{
        cout<<"No wrong reservations printed, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/9"<<endl<<endl;
    return score;

}

