<?php
namespace Tests;


use PHPUnit\Framework\TestCase;
use function App\ProgressCount;
require_once('App/ProgressCount.php');

class ProgressCountTest extends TestCase {
    public function test_count_progress_and_should_return_2(){
        $progressDays = Array(3, 4, 1, 2);
        $result = ProgressCount($progressDays);
        self::assertEquals(2, $result);
    }

    public function test_count_progress_and_should_return_3(){
        $progressDays = Array(10, 11, 12, 9, 10);
        $result = ProgressCount($progressDays);
        self::assertEquals(3, $result);
    }

    public function test_count_progress_and_should_return_1(){
        $progressDays = Array(6, 5, 4, 3, 2, 9);
        $result = ProgressCount($progressDays);
        self::assertEquals(1, $result);
    }

    public function test_count_progress_and_should_return_0(){
        $progressDays = Array(9,9);
        $result = ProgressCount($progressDays);
        self::assertEquals(0, $result);
    }
}