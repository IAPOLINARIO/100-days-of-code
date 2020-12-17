<?php

use function App\FindAndcountSkewersForType;
require_once('App/FindAndcountSkewersForType.php');

$skewers = Array(
    "--xo--x--ox--",
    "--xx--x--xx--",
    "--oo--o--oo--",
    "--xx--x--ox--",
    "--xx--x--ox--"
);
 FindAndcountSkewersForType($skewers);