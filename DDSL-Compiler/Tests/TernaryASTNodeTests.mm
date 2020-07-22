//
//  TernaryASTNodeTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"

@interface TernaryASTNodeTests : XCTestCase

@end

@implementation TernaryASTNodeTests

- (void)testTernary {
    auto result = DynamicDSLTestHelper::shared()->runExpr("true?123:456");
    XCTAssert(result == string("123"));
    result = DynamicDSLTestHelper::shared()->runExpr("false?123:456");
    XCTAssert(result == string("456"));
    result = DynamicDSLTestHelper::shared()->runExpr("1> 2?123:456");
    XCTAssert(result == string("456"));
    result = DynamicDSLTestHelper::shared()->runExpr("2 > 1?123:456");
    XCTAssert(result == string("123"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]>[object][rect][point][x]?123:456");
    XCTAssert(result == string("456"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]>=[object][rect][point][x]?123:[namex]");
    XCTAssert(result == string("johnx"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]>=[object][rect][point][x]?123:(false?123:'456x')");
    XCTAssert(result == string("456x"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]<[object][rect][point][x]?(true?\"456x\":123):(false?123:'456x')");
    XCTAssert(result == string("456x"));
}

@end
