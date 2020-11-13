
enum InputError: Error {
    case empty
    case invalid

    var description: String {
        switch self {
        default:
            return "Please inform an integer."
        }
    }
}

func parseInput(_ input: [String]) -> Result<Int, InputError> {
    guard input.count > 1 else {
        return .failure(.empty)
    }
    guard let value = Int(input[1]) else {
        return .failure(.invalid)
    }
    return .success(value)
}

func isPrime(_ value: Int) -> Bool {
    if value <= 1 {
        return false
    }
    if value <= 3 {
        return true
    }
    if value % 2 == 0 || value % 3 == 0 {
        return false
    }
    var i = 5
    while (i*i) <= value {
        if value % i == 0 || value % (i + 2) == 0 {
            return false
        }
        i += 6
    }

    return true
}

func findNextPrime(in value: Int) -> Int {
    if value <= 1 {
        return 2
    }
    var value = value
    while true {
        if isPrime(value) {
            return value
        }
        value += 1
    }
}

let input = parseInput(CommandLine.arguments)
switch input {
case .failure(let err): print(err.description)
case .success(let value):
    let prime = findNextPrime(in: value)
    print("The next prime is \(prime)")
}

