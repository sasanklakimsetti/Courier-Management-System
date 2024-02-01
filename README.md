# Courier-Management-System
TITLE: Courier Management System
An academic performed in my second semester.
Description: 

*The C Program “Courier Management System” was implemented using various concepts like File Handling,Module,Structure,switch case statements.

*This program lets user to add Courier records into the file,Display the added records on the screen and as well in file,Search the required data through various search filters,Update the various through various update filters and delete the record and sort the record.

*This is useful for small Courier Organisation as it contains some limitations and anomalies.


Module Explanation:

We have used six modules to implement this program namely:
*Insert
*Display
*Search
*Update
*Delete
*Sort

1)Insert Module: This module is used to insert the data into the file by giving Courier ID,Sender Name,Sender Address,Receiver Name and Receiver Address.There are limitations in this module that the string datatypes like Sender Name,Sender Address,Receiver Name,Receiver Address shouldn’t contain any spaces between the each datatype while entering,if so the input after the space will be given to next scan input.Instead of spaces,user can use underscore which defines space.

2)Display Module: This module makes the data to appear on the console/screen when the designated key was pressed by the system.

3)Search Module: This module lets the user to search the required Courier Information through various search filters such as by Courier ID,Sender Name,Sender Address,Receiver Name,Receiver Address.This also has a limitation that no spaces should be given while searching and the user should give the entire ID/Sender Name/Sender Address/Receiver Name/Receiver Address.

4)Update Module: This module lets the user to update Courier Information by providing the ID.If the ID was found in the file it’ll let the user to update the data through various update filters such as Sender Name,Sender Address,Receiver Name,Receiver Address.This also has a limitation that the user shouldn’t provide any spaces between the input of any data item.

5)Delete Module: This module lets the user to delete the Courier data for the required ID by providing the Courier ID.If the provided ID matches with the any ID in the file,then it will delete that particular entry.

6)Sort Module: This module lets the user to sort the entries in ascending order which has been implemented using ‘Bubble Sort’.
