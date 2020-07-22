//
//  SquareBracketsASTNodeTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"

@interface SquareBracketsASTNodeTests : XCTestCase

@end

@implementation SquareBracketsASTNodeTests

- (void)testSBOne {
    auto result = DynamicDSLTestHelper::shared()->runExpr("[agex]");
    XCTAssert(result == string("32"));
    result = DynamicDSLTestHelper::shared()->runExpr("[namex]");
    XCTAssert(result == string("johnx"));
    auto key = DynamicDSLTestHelper::shared()->runExpr("'na'+'mex'");
    result = DynamicDSLTestHelper::shared()->runExpr("["+ key +"]");
    XCTAssert(result == string("johnx"));
}
- (void)testSBTwo {
    auto result = DynamicDSLTestHelper::shared()->runExpr("[size][width]");
    XCTAssert(result == string("20"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][height]");
    XCTAssert(result == string("30"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]*[size][height]");
    XCTAssert(result == string("600"));
}
- (void)testSBMutil {
    auto result = DynamicDSLTestHelper::shared()->runExpr("[object][rect][point][x] *[size][width]");
    XCTAssert(result == string("4000"));
    result = DynamicDSLTestHelper::shared()->runExpr("[object][rect][point][x] +[size][width]+ [object][rect][point][name] + 'abc'");
    XCTAssert(result == string("220小强abc"));
}
@end
