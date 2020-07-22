
#include "SemaASTNodeObject.h"

const DDSL::Type DDSL::SemaASTNodeObject::getType() {
    return this->type;
}
const string DDSL::SemaASTNodeObject::getTypeText() {
    auto type = getType();
    switch (type) {
        case String:
            return "String";
            break;
        case Number:
            return "Number";
            break;
        case Bool:
            return "Bool";
            break;
        case Object:
            return "Object";
            break;
        default:
            break;
    }
    return "Unknow ASTNode Type";
}
const string DDSL::SemaASTNodeObject::getText() {
    if(this->value.has_value()) {
        auto type = getType();
        if(type == String) {
            return any_cast<string>(this->value);
        } else if(type == Number) {
            ostringstream oss;
            string clsName = this->value.type().name();
            if(clsName == "d")
                oss << any_cast<double>(this->value);
            else if(clsName == "i")
                oss << any_cast<int>(this->value);
            return oss.str();
        } else if(type == Bool) {
            if(any_cast<bool>(this->value)) return "true";
            else return "false";
        } else if(type == Object) {
            string clsName = this->value.type().name();
            if(this->subType == S_ASTNodeObject) {
                return "[SemaASTNodeObject]";
            } else if(this->subType == S_Object) {
                return "[DDObject]";
            } else {
                return "";
            }
        }
        return "";
    }
    return "";
}
