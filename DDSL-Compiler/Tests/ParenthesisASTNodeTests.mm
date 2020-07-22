//
//  ParenthesisASTNodeTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"

@interface ParenthesisASTNodeTests : XCTestCase

@end

@implementation ParenthesisASTNodeTests

- (void)testPriority {
    auto result = DynamicDSLTestHelper::shared()->runExpr("123+5*2");
    XCTAssert(result == string("133"));
    result = DynamicDSLTestHelper::shared()->runExpr("123-5*2");
    XCTAssert(result == string("113"));
    result = DynamicDSLTestHelper::shared()->runExpr("123+5/2");
    XCTAssert(result == string("125.5"));
    result = DynamicDSLTestHelper::shared()->runExpr("123-5/2");
    XCTAssert(result == string("120.5"));
    result = DynamicDSLTestHelper::shared()->runExpr("132+4*2-3/2+100.2");
    XCTAssert(result == string("238.7"));
    result = DynamicDSLTestHelper::shared()->runExpr("132+4*(2-3)/2+100.2");
    XCTAssert(result == string("230.2"));
    result = DynamicDSLTestHelper::shared()->runExpr("5 * ((1 + 2) * 3 / 2 * (10 - 8))");
    XCTAssert(result == string("45"));
    result = DynamicDSLTestHelper::shared()->runExpr("(true?3:2)");
    XCTAssert(result == string("3"));
}

@end
