//
//  Compiler.cpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/9.
//  Copyright © 2020 坏人. All rights reserved.
//

#include "Compiler.h"

using namespace DDSL;

SemaForStmt Complier::compileForStmt() {
    return SemaForStmt(this->irs, new DDObject(jsonObject, variable));
}

SemaFrame Complier::compile() {
    return DDSL::SemaFrame(this->irs, jsonObject, variable);
}



