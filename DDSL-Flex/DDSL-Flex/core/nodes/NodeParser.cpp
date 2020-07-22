//
//  NodeParser.cpp
//  Core
//
//  Created by youxiaobin on 2020/6/23.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#include "NodeParser.h"
#include <DDSL-Compiler/DDSL-Compiler.h>
#include <DDSL-Runtime/DDSL-Runtime.h>

static void ParseXMLElementAttribute(tinyxml2::XMLElement *element, Node *node) {
    const tinyxml2::XMLAttribute *attribute = element->FirstAttribute();
    while (attribute) {
        const string name = attribute->Name();
        const string value = attribute->Value();
        debugPrint("%s: (%s: %s)", element->Name(), name.c_str(), value.c_str());
        attribute = attribute->Next();
        if(name == "type") continue;
        else if(name == "flexDirection") {
            node->setFlexDirection(DDSL::util::ConvertStringToFlexDirection(value));
        } else if(name == "justify") {
            node->setJustifyContent(DDSL::util::ConvertStringToJustify(value));
        } else if(name == "alignSelf") {
            node->setAlignSelf(DDSL::util::ConvertStringToAlign(value));
        } else if(name == "alignItems") {
            node->setAlignItems(DDSL::util::ConvertStringToAlign(value));
        } else if(name == "positionType") {
            node->setPositionType(DDSL::util::ConvertStringToPositionType(value));
        } else if(name == "wrap") {
            node->setFlexWrap(DDSL::util::ConvertStringToWrap(value));
        } else if(name == "overflow") {
            node->setOverflow(DDSL::util::ConvertStringToOverflow(value));
        } else if(name == "display") {
            node->setDisplay(DDSL::util::ConvertStringToDisplay(value));
        } else if(name == "flex") {
            node->setFlex(stof(value));
        } else if(name =="flexGrow") {
            node->setFlexGrow(stof(value));
        } else if(name == "flexShrink") {
            node->setFlexShrink(stof(value));
        } else if(name == "top") {
            node->setPositionTop(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "bottom") {
            node->setPositionBottom(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "left") {
            node->setPositionLeft(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "right") {
            node->setPositionRight(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "marginTop") {
            node->setMarginTop(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "marginBottom") {
            node->setMarginBottom(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "marginLeft") {
            node->setMarginLeft(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "marginRight") {
            node->setMarginRight(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "paddingTop") {
            node->setPaddingTop(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "paddingBottom") {
            node->setPaddingBottom(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "paddingLeft") {
            node->setPaddingLeft(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "paddingRight") {
            node->setPaddingRight(DDSL::util::ConvertStringToYGValue(value));
        } else if(name == "width") {
            if(value == "auto") {
                node->setWidthAuto();
            } else if(value.rfind("%") != string::npos) {
                float percent = stof(value.substr(0, value.length() - 1));
                node->setWidthPercent(percent);
            } else {
                node->setWidth(stof(value));
            }
        } else if(name == "height") {
            if(value == "auto") {
                node->setHeightAuto();
            } else if(value.rfind("%") != string::npos) {
                float percent = stof(value.substr(0, value.length() - 1));
                node->setHeightPercent(percent * 100);
            } else {
                node->setHeight(stof(value));
            }
        } else if(name == "minWidth") {
            node->setMinWidth(stof(value));
        } else if(name == "minHeight") {
            node->setMinHeight(stof(value));
        } else if(name == "maxWidth") {
            node->setMaxWidth(stof(value));
        } else if(name == "maxHeight") {
            node->setMaxHeight(stof(value));
        } else if(name == "color") {
            node->getDisplayAttribute().foregroundColorHex = value;
        } else if(name == "backgroundColor") {
            node->getDisplayAttribute().backgroundColorHex = value;
        } else if(name == "borderWidth") {
            node->getDisplayAttribute().border.width = stof(value);
        } else if(name == "borderColor") {
            node->getDisplayAttribute().border.colorHex = value;
        } else if(name == "radius") {
            node->getDisplayAttribute().radius = stof(value);
        } else if(name == "shadowColor") {
            node->getDisplayAttribute().shadow.colorHex = value;
        } else if(name == "shadowOffsetX") {
            node->getDisplayAttribute().shadow.offset.width = stof(value);
        } else if(name == "shadowOffsetY") {
            node->getDisplayAttribute().shadow.offset.height = stof(value);
        } else if(name == "shadowRadius") {
            node->getDisplayAttribute().shadow.radius = stof(value);
        } else if(name == "shadowOpacity") {
            node->getDisplayAttribute().shadow.opacity = stof(value);
        } else if(name == "text") {
            if(node->getNodeType() == enumeration::label) {
                TextNode *tn = (TextNode *)node;
                tn->setText(value);
            }
        } else if(name == "fontSize") {
            if(node->getNodeType() == enumeration::label) {
                TextNode *tn = (TextNode *)node;
                tn->setFontSize(stoi(value));
            }
        } else if(name == "lineNumber") {
            if(node->getNodeType() == enumeration::label) {
                TextNode *tn = (TextNode *)node;
                tn->setMaxLineNumber(stoi(value));
            }
        } else {
            warningPrint("未支持的属性: %s", value.c_str());
        }
    }
}
static void ParseXMLElement(tinyxml2::XMLElement *element, Node *node, float scale, Node::_NodeMeasureFunc func) {
    ParseXMLElementAttribute(element, node);
    tinyxml2::XMLElement *child = element->FirstChildElement();
    while (child) {
        enumeration::NodeType nodeType = DDSL::util::ConvertStringToNodeType(child->Name());
        Node *childNode;
        if(nodeType == enumeration::label) {
            childNode = new TextNode(scale, nodeType, func);
        } else {
            childNode = new Node(scale, nodeType, func);
        }
        ParseXMLElement(child, childNode, scale, func);
        node->appendNode(childNode);
        child = child->NextSiblingElement();
    }
}

Node *NodeParser::LoadXML(const char *path,
                          float scale,
                          string json,
                          map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable,
                          Node::_NodeMeasureFunc func) {
    string err;
    auto jsonObject = json11::Json::parse(json, err);
    if(!path) return NULL;
    DDSL::DDXMLBinding *db = new DDSL::DDXMLBinding(path, jsonObject, variable);
    db->BindingXML();
    tinyxml2::XMLDocument doc;
    db->GetDoc()->DeepCopy(&doc);
    delete db;
    tinyxml2::XMLElement *rootElement = doc.RootElement();
    
    if(!rootElement) return NULL;
    /// Get type of root node.
    enumeration::NodeType rootNodeType = DDSL::util::ConvertStringToNodeType(rootElement->Name());
    Node *rootNode;
    if(rootNodeType == enumeration::label) {
        rootNode = new TextNode(scale, rootNodeType, func);
    } else {
        rootNode = new Node(scale, rootNodeType, func);
    }
    ParseXMLElement(rootElement, rootNode, scale, func);
    return rootNode;
}
