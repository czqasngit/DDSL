//
//  UnitaryASTNodeTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"

@interface UnitaryASTNodeTests : XCTestCase

@end

@implementation UnitaryASTNodeTests

- (void)testIncream {
    auto result = DynamicDSLTestHelper::shared()->runExpr("3 ++");
    XCTAssert(result == string("4"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]++");
    XCTAssert(result == string("21"));
    result = DynamicDSLTestHelper::shared()->runExpr("10 * 3++");
    XCTAssert(result == to_string(10 * 4));
    result = DynamicDSLTestHelper::shared()->runExpr("(10 * 3)++");
    XCTAssert(result == to_string(31));
}
- (void)testDecream {
    auto result = DynamicDSLTestHelper::shared()->runExpr("3 --");
    XCTAssert(result == string("2"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]--");
    XCTAssert(result == string("19"));
    result = DynamicDSLTestHelper::shared()->runExpr("10 * 3--");
    XCTAssert(result == to_string(10 * 2));
    result = DynamicDSLTestHelper::shared()->runExpr("(10 * 3)--");
    XCTAssert(result == to_string(29));
}
- (void)testMix {
    auto result = DynamicDSLTestHelper::shared()->runExpr("3++--");
    XCTAssert(result == string("3"));
}

@end
