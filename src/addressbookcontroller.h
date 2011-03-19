#ifndef CONTROLLER_ADDRESS_BOOK_H
#define CONTROLLER_ADDRESS_BOOK_H


#include "contact.h"
#include "addressbookmodel.h"
#include "addressbookview.h"
#include "errorinfo.h"


/************************************************************
    Class: AddressBookController

    Author: Phil Grohe

    Main application controller for the address book program,
    The intermediary between the UI and the data storage
    object.  Routes UI actions to data store and returns
    data to UI. Interprets errors from data store and
    passes ErrorInfo objects back up to UI
************************************************************/

class AddressBookController
{
    public:

        //Interface to UI module
        ErrorInfo submitContact(const Contact &c);
        ErrorInfo deleteContact(const Contact::ContactId id);
        ErrorInfo editContact(const Contact::ContactId id);

        bool activateEditMode(void);
        bool disableEditMode(void);

        void start(void);

        //Stores reference to AddressBookModel  abstract base class
        //allowing for different kinds of back end data storage
        //provided it implements the AddressBookModel interface
        explicit AddressBookController(AddressBookModel &d);
        ~AddressBookController();
        
    private:
        AddressBookModel &dataStore; 
        AddressBookView *frontEnd;
};


#endif
