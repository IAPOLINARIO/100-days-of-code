import XCTest
import class Foundation.Bundle

final class PairOfSocksTests: XCTestCase {
    func testDrawer() throws {
        let output1 = try runProgram(args: ["AA"])
        XCTAssertEqual(output1, "Joseph has 1 pairs of sockets.")

        let output2 = try runProgram(args: ["ABABC"])
        XCTAssertEqual(output2, "Joseph has 2 pairs of sockets.")

        let output3 = try runProgram(args: ["CABBACCC"])
        XCTAssertEqual(output3, "Joseph has 4 pairs of sockets.")

        let output4 = try runProgram(args: ["123141"])
        XCTAssertEqual(output4, "Joseph has 1 pairs of sockets.")

        let output5 = try runProgram(args: ["A", "B", "C", "A", "E", "A", "C", "A", "B"])
        XCTAssertEqual(output5, "Joseph has 4 pairs of sockets.")
    }

    func runProgram(args: [String]) throws -> String? {
        let binary = productsDirectory.appendingPathComponent("PairOfSocks")

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
        ("testDrawer", testDrawer),
    ]
}
