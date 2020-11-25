defmodule Day02 do
  def findNemo(text) do
    nemoPosition = Enum.find_index(String.split(text," "), fn x -> x === "Nemo" end)
    if (nemoPosition != nil) do
      "I found Nemo at #{nemoPosition+1}!"
    else
      "I can't find Nemo :("
    end
  end
end
