//
//  PrimaryASTNodeTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"

@interface PrimaryASTNodeTests : XCTestCase

@end

@implementation PrimaryASTNodeTests

- (void)setUp {

}


- (void)testId {
    map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;
    variable["money"] = make_shared<DDSL::SemaASTNodeObject>(300.2);
    variable["age"] = make_shared<DDSL::SemaASTNodeObject>(30);
    variable["name"] = make_shared<DDSL::SemaASTNodeObject>("John");
    auto result = DynamicDSLTestHelper::shared()->runExpr("money", variable);
    XCTAssert(result == string("300.2"));
    result = DynamicDSLTestHelper::shared()->runExpr("age", variable);
    XCTAssert(result == string("30"));
    result = DynamicDSLTestHelper::shared()->runExpr("name", variable);
    XCTAssert(result == string("John"));
    result = DynamicDSLTestHelper::shared()->runExpr("me");
    XCTAssert(result == string(""));
}

- (void)testString {
    auto result = DynamicDSLTestHelper::shared()->runExpr("'123'");
    XCTAssert(result == string("123"));
    result = DynamicDSLTestHelper::shared()->runExpr("\"abcd上\"");
    XCTAssert(result == string("abcd上"));
    result = DynamicDSLTestHelper::shared()->runExpr("''");
    XCTAssert(result == string(""));
    result = DynamicDSLTestHelper::shared()->runExpr("\"\"");
    XCTAssert(result == string(""));
}
- (void)testInt {
    auto result = DynamicDSLTestHelper::shared()->runExpr("1123");
    XCTAssert(result == "1123");
}
- (void)testDouble {
    auto result = DynamicDSLTestHelper::shared()->runExpr("1123.13");
    XCTAssert(result == "1123.13");
}
- (void)testBool {
    auto result = DynamicDSLTestHelper::shared()->runExpr("true");
    XCTAssert(result == "true");
    result = DynamicDSLTestHelper::shared()->runExpr("false");
    XCTAssert(result == "false");
}

- (void)testObject {
    map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;
    variable["money"] = make_shared<DDSL::SemaASTNodeObject>(make_shared<DDSL::SemaASTNodeObject>(300.2));
    auto result = DynamicDSLTestHelper::shared()->runExpr("money", variable);
    XCTAssert(result == string("[SemaASTNodeObject]"));
}

@end
