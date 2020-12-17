import XCTest

#if !canImport(ObjectiveC)
public func allTests() -> [XCTestCaseEntry] {
    return [
        testCase(PairOfSocksTests.allTests),
    ]
}
#endif
