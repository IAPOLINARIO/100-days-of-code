enum InputError: Error {
    case invalidAmount
    case invalidFormat

    var description: String {
        switch self {
        case .invalidFormat: return "Please type in the format ex: 3,2,1,5"
        case .invalidAmount: return "You need to type in the miles correctly"
        }
    }
}

func readInput() -> Result<[Int], InputError> {
    guard CommandLine.arguments.count > 1 else {
        return .failure(InputError.invalidAmount)
    }
    let input = CommandLine.arguments[1]
    let miles = input.split(separator: ",").compactMap { Int($0) }
    guard miles.count > 0 else {
        return .failure(InputError.invalidFormat)
    }
    return .success(miles)
}

func calculateProgress(miles: [Int]) -> Int {
    var previous = -1
    var progress = 0
    for mile in miles {
        if previous == -1 {
            previous = mile
            continue
        }
        let progressed = mile > previous
        progress += progressed ? 1 : 0
        previous = mile
    }
    return progress
}

switch readInput() {
case .failure(let error): print(error.description)
case .success(let miles):
    let progress = calculateProgress(miles: miles)
    print("Johnny had \(progress) days of progress.")
}

