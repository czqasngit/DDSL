//
//  DynamicDSLTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "DynamicDSLTestHelper.h"


@interface DynamicDSLTests : XCTestCase
@end

@implementation DynamicDSLTests

- (void)testBasic {
    std::string result = DynamicDSLTestHelper::shared()->runExpr("3 + 2 * 5");
    XCTAssert(result == "13");
}

@end
