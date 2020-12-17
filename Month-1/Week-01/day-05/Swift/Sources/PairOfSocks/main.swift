
func readInput() -> String {
    let args = CommandLine.arguments
    guard args.count > 1 else {
        return ""
    }
    return args[1..<args.count].joined()
}

struct PairCounter {
    private let drawer: Dictionary<String.Element, Int>
    let pairs: Int

    init() {
        drawer = [:]
        pairs = 0
    }

    init(_ drawer: Dictionary<String.Element, Int>, pairs: Int) {
        self.pairs = pairs
        self.drawer = drawer
    }

    func update(sock: String.Element) -> PairCounter {
        var drawer = self.drawer
        var pairs = self.pairs
        if var foundSocks = drawer[sock] {
            foundSocks += 1
            pairs += foundSocks % 2 == 0 ? 1 : 0
            drawer[sock] = foundSocks
        } else {
            drawer[sock] = 1
        }
        return PairCounter(drawer, pairs: pairs)
    }
}

func findPairs(in input: String) -> Int {
    let drawer = input.reduce(PairCounter()) { $0.update(sock: $1) }
    return drawer.pairs
}

let input = readInput()
let pairs = findPairs(in: input)

print("Joseph has \(pairs) pairs of sockets.")
