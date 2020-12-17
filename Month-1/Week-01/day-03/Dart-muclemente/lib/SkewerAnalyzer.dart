
class Outputs {
  static String skewers(int vegetarian, int meat) {
    return "Your barbecue has ${vegetarian} vegetarian skewers and ${meat} non-veggie skewers.";
  }

  static String noSkewers() {
    return "There are no skewers in your barbecue...";
  }
}

class Skewer {
  static const _meatKeyword = "x";
  bool hasMeat;
  
  Skewer(String skewerString) {
    _parseString(skewerString);
  }

  void _parseString(String string) {
    hasMeat = string.contains(_meatKeyword);
  }
}

class Barbecue {
  int vegetarian = 0;
  int nonVegetarian = 0;

  void update(Skewer skewer) {
    if (skewer.hasMeat) {
      nonVegetarian += 1;
    } else {
      vegetarian += 1;
    }
  }
}

class SkewerAnalyzer {

  void analyze(List<String> arguments) {
    if (arguments.isEmpty) {
      print(Outputs.noSkewers());
      return;
    }
    var barbecue = Barbecue();
    arguments.forEach((element) {
      barbecue.update(Skewer(element));
    });
    print(Outputs.skewers(barbecue.vegetarian, barbecue.nonVegetarian));
  }
}

