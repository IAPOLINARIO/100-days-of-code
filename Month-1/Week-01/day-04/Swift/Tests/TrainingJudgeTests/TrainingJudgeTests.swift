import XCTest
import class Foundation.Bundle

final class TrainingJudgeTests: XCTestCase {

    func testProgress() throws {
        let output1 = try runProgramWith(params: ["1,2,3,4"])
        XCTAssertEqual(output1, "Johnny had 3 days of progress.")

        let output2 = try runProgramWith(params: ["0,1"])
        XCTAssertEqual(output2, "Johnny had 1 days of progress.")

        let output3 = try runProgramWith(params: ["1,1,1,1"])
        XCTAssertEqual(output3, "Johnny had 0 days of progress.")

        let output4 = try runProgramWith(params: ["10,11,12,9,10"])
        XCTAssertEqual(output4, "Johnny had 3 days of progress.")

        let output5 = try runProgramWith(params: ["6,5,4,3,2,9"])
        XCTAssertEqual(output5, "Johnny had 1 days of progress.")
    }

    func testInvalidInputs() throws {
        let output1 = try runProgramWith(params: [])
        XCTAssertEqual(output1, "You need to type in the miles correctly")

        let output2 = try runProgramWith(params: ["i ,12 a"])
        XCTAssertEqual(output2, "Please type in the format ex: 3,2,1,5")
    }

    func runProgramWith(params: [String]) throws -> String? {
        let binary = productsDirectory.appendingPathComponent("TrainingJudge")

        let process = Process()
        process.executableURL = binary
        process.arguments = params

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
        ("testExample", testProgress),
    ]
}
