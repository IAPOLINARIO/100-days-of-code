defmodule Day01Test do
  use ExUnit.Case
  doctest Day01

  test "convert 65 years old in days" do
    assert Day01.calcAge(65) == 23725
  end

  test "convert 0 years old in days" do
    assert Day01.calcAge(0) == 0
  end

  test "convert 20 years old in days" do
    assert Day01.calcAge(20) == 7300
  end
end
