//
//  ScriptTests.m
//  ScriptTests
//
//  Created by youxiaobin on 2020/7/21.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DDExprHelper.h"

using namespace DDSL;
using namespace Script;

@interface ScriptTests : XCTestCase

@end

@implementation ScriptTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExprValid {
    auto r = DDExprHelper::IsExprValid("{{ a > b }}");
    XCTAssert(r);
    r = DDExprHelper::IsExprValid(" {{ a > b }} ");
    XCTAssert(r);
    r = DDExprHelper::IsExprValid("a > b");
    XCTAssert(!r);
    r = DDExprHelper::IsExprValid("{{a > b");
    XCTAssert(!r);
    r = DDExprHelper::IsExprValid("a > b}}");
    XCTAssert(!r);
    r = DDExprHelper::IsExprValid("{a > b}");
    XCTAssert(!r);
    
}

@end
