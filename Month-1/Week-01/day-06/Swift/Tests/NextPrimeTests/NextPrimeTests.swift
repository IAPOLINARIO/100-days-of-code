import XCTest
import class Foundation.Bundle

final class NextPrimeTests: XCTestCase {
    func testPrimes() throws {
        let output1 = try runProgram(args: ["12"])
        let output2 = try runProgram(args: ["24"])
        let output3 = try runProgram(args: ["11"])
        let output4 = try runProgram(args: ["1203312312421122222"])

        XCTAssertEqual(output1, "The next prime is 13")
        XCTAssertEqual(output2, "The next prime is 29")
        XCTAssertEqual(output3, "The next prime is 11")
        XCTAssertEqual(output4, "The next prime is 1203312312421122359")
    }

    func testInvalid() throws {
        let output1 = try runProgram(args: [""])
        let output2 = try runProgram(args: ["a"])
        let output3 = try runProgram(args: ["12033123124211222222"])

        XCTAssertEqual(output1, "Please inform an integer.")
        XCTAssertEqual(output2, "Please inform an integer.")
        XCTAssertEqual(output3, "Please inform an integer.")
    }

    func runProgram(args: [String]) throws -> String? {
        let binary = productsDirectory.appendingPathComponent("NextPrime")
        let process = Process()
        process.executableURL = binary
        process.arguments = args

        let pipe = Pipe()
        process.standardOutput = pipe

        try process.run()
        process.waitUntilExit()

        let data = pipe.fileHandleForReading.readDataToEndOfFile()
        return String(data: data, encoding: .utf8)?.replacingOccurrences(of: "\n", with: "")
    }

    /// Returns path to the built products directory.
    var productsDirectory: URL {
      #if os(macOS)
        for bundle in Bundle.allBundles where bundle.bundlePath.hasSuffix(".xctest") {
            return bundle.bundleURL.deletingLastPathComponent()
        }
        fatalError("couldn't find the products directory")
      #else
        return Bundle.main.bundleURL
      #endif
    }

    static var allTests = [
        ("testPrimes", testPrimes),
    ]
}
