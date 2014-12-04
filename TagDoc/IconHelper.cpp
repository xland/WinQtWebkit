#include "IconHelper.h"

IconHelper* IconHelper::_instance = 0;
IconHelper::IconHelper(QObject*) :
    QObject(qApp)
{
    int fontId = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/res/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
}

void IconHelper::SetIcon(QLabel* ctl,QChar c,int size)
{
    iconFont.setPointSize(size);
    ctl->setFont(iconFont);
    ctl->setText(c);
}

void IconHelper::SetIcon(QPushButton* ctl,QChar c,int size)
{
    iconFont.setPointSize(size);
    ctl->setFont(iconFont);
    ctl->setText(c);
}
