<?php
namespace App;

function ProgressCount($progressDays){
    $lastItem = $progressDays[0];
    $countProgress = 0;
    foreach($progressDays as $item){
        if($item > $lastItem) $countProgress++;
        $lastItem = $item;
    }
    return $countProgress;
}