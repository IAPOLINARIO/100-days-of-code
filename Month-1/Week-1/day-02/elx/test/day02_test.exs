defmodule Day02Test do
  use ExUnit.Case
  doctest Day02

  test "test without Nemo" do
    assert Day02.findNemo("I am finding !") == "I can't find Nemo :("
  end

  test "test Nemo at position 4" do
    assert Day02.findNemo("I am finding Nemo !") == "I found Nemo at 4!"
  end

  test "test Nemo at position 1" do
    assert Day02.findNemo("Nemo is me") == "I found Nemo at 1!"
  end

  test "test Nemo at position 2" do
    assert Day02.findNemo("I Nemo am") == "I found Nemo at 2!"
  end
end
