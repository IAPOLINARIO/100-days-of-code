<?php
namespace Tests;


use PHPUnit\Framework\TestCase;
use function App\FindAndcountSkewersForType;
require_once('App/FindAndcountSkewersForType.php');

class FindAndcountSkewersForTypeTest extends TestCase {
    public function test_find_without_vegan_skewers(){
        $skewers = Array(
            "--xo--x--ox--",
            "--xx--x--xx--",
            "--xx--x--ox--",
            "--xx--x--ox--"
        );
        $result = FindAndcountSkewersForType($skewers);
        self::assertEquals([0,4], $result);
    }

    public function test_find_with_one_vegan(){
        $skewers = Array(
            "--xo--x--ox--",
            "--xx--x--xx--",
            "--xx--x--ox--",
            "--oo--o--oo--",
            "--xx--x--ox--"
        );
        $result = FindAndcountSkewersForType($skewers);
        self::assertEquals([1,4], $result);
    }

    public function test_find_with_two_vegan(){
        $skewers = Array(
            "--xo--x--ox--",
            "--xx--x--xx--",
            "--xx--x--ox--",
            "--oo--o--oo--",
            "--oo--o--oo--",
            "--xx--x--ox--"
        );
        $result = FindAndcountSkewersForType($skewers);
        self::assertEquals([2,4], $result);
    }
    public function test_find_with_not_skewers(){
        $skewers = Array();
        $result = FindAndcountSkewersForType($skewers);
        self::assertEquals("Please go get more skewers :)", $result);
    }

    public function test_find_with_null_skewers(){
        $result = FindAndcountSkewersForType(null);
        self::assertEquals("Please go get more skewers :)", $result);
    }
}