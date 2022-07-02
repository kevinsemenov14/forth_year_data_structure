/*
 * main.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: ksemenov0
 */

#include "kevinMap.h"
int main()
{


kevinmap maps;

//18 Laguna Niguel
//41 Mission Viejo
//22 San Clemente
//44 Irvine
//Delete key 41
//58 Lake Forest
//32 San Diego
//49 Anaheim
//Delete key 58
//31 Los Angeles
//17 Orange
//72 Palms Springs
//41 Riverside
//Delete key 73
//19 Brea
//60 Santa Ana
//35 Tustin
//103 Oceanside
//11 La Jolla
//18 Del Mar
//22 Aliso Viejo
//49 Laguna Beach
//Delete key 41
//42 Vista
//49 San Diego
//99 San Juan
//29 Dana Point
//88 El Segundo
//41 San Clemente
//62 Laguna Hills



cout <<"Kevin Semenov Class CS1D Double hashing program Assigment 7\n\n";
cout << "Develop fully documented software to store the\n"
		"following keys and values into a data structure(s) \n"
		"of your choice (array(s), vector(s), etc.) using the \n"
		"double hashing algorithm.   \n"
		"Output what data structure you chose. Use a map (not a dictionary).\n\n";

cout << "This program is using a vector class to make the map and will store\n"
		"in data using h(k) = k mod 31 h’(k) = 17 - k mod 17 if the same key is enterd \n"
		"the map it will repalce the value and keep the key\n";

cout << endl;
maps.put(18,"Laguna Niguel");
maps.put(41,"Mission Viejo ");
maps.put(22,"San Clemente ");
cout << maps.find(22)<< endl;maps.put(44,"Irvine");
maps.erase(41);
maps.put(58,"Lake Forest");

maps.put(32,"San Diego ");
maps.put(49,"Anaheim");
maps.erase(58);
maps.put(31,"Los Angeles");
maps.put(17,"Orange");
maps.put(72,"Palms Springs");
maps.put(41,"Riverside ");
maps.erase(73);
maps.put(19,"Brea");
maps.put(60,"Santa Ana");
maps.put(35,"Tustin");
maps.put(103,"Oceanside");
maps.put(11,"La Jolla");
maps.put(18,"Del Mar");
maps.put(22,"Aliso Viejo");
maps.put(49,"Laguna Beach");
maps.erase(41);
maps.put(42,"Vista");
maps.put(49,"San Diego");
maps.put(99,"San Juan");
maps.put(29,"Dana Point");
maps.put(88,"El Segundo ");
maps.put(41,"San Clemente");
maps.put(62,"Laguna Hills");
cout << endl;
maps.print();
}


