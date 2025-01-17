//
// Created by cc on 2019-02-13.
//

#ifndef STALK_V2_ABOUTWND_H
#define STALK_V2_ABOUTWND_H

#include "CustomUi/UShadowWnd.h"
#include <QLabel>

/**
* @description: AboutWnd
* @author: cc
* @create: 2019-02-13 14:56
**/
class AboutWnd : public UShadowDialog{
public:
    explicit AboutWnd(QWidget * parent = nullptr);
    ~AboutWnd() override;

public:

private:
    void initUi();

private:
    QLabel* _pVersionLabel;
    QLabel* _pCopyrightLabel;
    QLabel* _pBuildDateTimeLabel;
};


#endif //STALK_V2_ABOUTWND_H
