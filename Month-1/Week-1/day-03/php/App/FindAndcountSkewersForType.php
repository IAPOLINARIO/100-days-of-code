<?php
namespace  App;
function FindAndcountSkewersForType($skewers){
    if($skewers === null or empty($skewers))  return "Please go get more skewers :)";

    $totalVegetarianSkewers = 0;
    $totalNonVegetarianSkewers = 0;

    foreach ($skewers as $skewer){
        if(mb_strpos($skewer, 'x') !== false){
            $totalNonVegetarianSkewers++;
        }else{
            $totalVegetarianSkewers++;
        }
    }

    return [
        $totalVegetarianSkewers,
        $totalNonVegetarianSkewers
    ];
}