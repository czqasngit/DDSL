//
//  BinaryASTNodeTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"

@interface BinaryASTNodeTests : XCTestCase

@end

@implementation BinaryASTNodeTests

- (void)testBinary {
    auto result = DynamicDSLTestHelper::shared()->runExpr("10 * 3");
    XCTAssert(result == string("30"));
    result = DynamicDSLTestHelper::shared()->runExpr("12 /3");
    XCTAssert(result == string("4"));
    result = DynamicDSLTestHelper::shared()->runExpr("10 / 2");
    XCTAssert(result == string("5"));
    result = DynamicDSLTestHelper::shared()->runExpr("10*3");
    XCTAssert(result == string("30"));
    result = DynamicDSLTestHelper::shared()->runExpr("10%3");
    XCTAssert(result == string("1"));
    result = DynamicDSLTestHelper::shared()->runExpr("10+ 3");
    XCTAssert(result == string("13"));
    result = DynamicDSLTestHelper::shared()->runExpr("'10'+ '3'");
    XCTAssert(result == string("103"));
    result = DynamicDSLTestHelper::shared()->runExpr("10-3");
    XCTAssert(result == string("7"));
    result = DynamicDSLTestHelper::shared()->runExpr("10<3");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("10>3");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]<[object][rect][point][x]");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]<=[object][rect][point][x]");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]>[object][rect][point][x]");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]>=[object][rect][point][x]");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]+[object][rect][point][x]");
    XCTAssert(result == string("220"));
    result = DynamicDSLTestHelper::shared()->runExpr("[size][width]*[object][rect][point][x]");
    XCTAssert(result == string("4000"));
    result = DynamicDSLTestHelper::shared()->runExpr("100 == 100");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("100 != 100");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("100 == 101");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("100 != 101");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("'100' == 100");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("'100' == '1' + '00'");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("100 == '1' + '00'");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("100 + '' == '1' + '00'");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("'10'+'0' == '100'");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("'10'+'0' == '100' && true");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("'10'+'0' == '100' && false");
    XCTAssert(result == string("false"));
    result = DynamicDSLTestHelper::shared()->runExpr("'10'+'0' == '100' || true");
    XCTAssert(result == string("true"));
    result = DynamicDSLTestHelper::shared()->runExpr("'10'+'0' == '100' || false");
    XCTAssert(result == string("true"));
}

@end
