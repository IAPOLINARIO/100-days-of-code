<?php
function FindNemo($text = ""){
    $nemo = "Nemo";
    $explodeText = explode(" ", $text);

    foreach($explodeText as  $key=>$value){
        if($value == $nemo){
            $position = $key + 1;
            return "I found Nemo at ".$position;
        }
    }
    
    return "I can't find Nemo :(";
}