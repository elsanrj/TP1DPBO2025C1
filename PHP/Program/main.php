<?php
include "Petshop.php";

$ps = new Petshop();

// list
$List[] = $ps->add("001", "DogTreats", "Makanan", 55000, "001.jpg");
$List[] = $ps->add("002", "KalungBell", "Perhiasan", 25000, "002.jpg");
$List[] = $ps->add("003", "ShampoKutu", "AlatMandi", 15000, "003.jpg");

// show 
$ps->show($List);

// find and update 
$ps->update($List, "004", "Royal Kenjo", "Makanan", 10000, "004.jpg");
$ps->update($List, "001", "CatTreats", "Makanan", 60000, "004.jpg");

// show
$ps->show($List);

// find and delete 
unset($List[$ps->find($List, "003")]);

// show
$ps->show($List);