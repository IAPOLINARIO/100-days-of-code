
class Outputs {
  static String foundIn(int position)   {
    if (position == -1) {
      return notFound();
    }
    return "I found nemo at ${position + 1}!";
  }

  static String notFound() {
    return "I can't find Nemo :(";
  }
}

class NemoFinder {
  static const nemoKeyword = "Nemo"; 

  void findIn(List<String> arguments) {
    if (arguments.isEmpty) {
      print(Outputs.notFound());
      return;
    }
    var placesToLook = arguments[0].split(" ");
    var found = placesToLook.indexWhere((term) => term == nemoKeyword);
    print(Outputs.foundIn(found));
  }
}

