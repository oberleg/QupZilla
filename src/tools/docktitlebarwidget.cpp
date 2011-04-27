/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2011  nowrep
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "docktitlebarwidget.h"

DockTitleBarWidget::DockTitleBarWidget(const QString &title, QWidget* parent) :
    QWidget(parent)
{
    setupUi(this);
#ifdef Q_WS_X11
    closeButton->setIcon(QIcon(style()->standardIcon(QStyle::SP_DialogCloseButton).pixmap(16,16)));
#else
    closeButton->setIcon(QIcon(QIcon(":/icons/faenza/close.png").pixmap(16,16)));
#endif
    label->setText(title);
    connect(closeButton, SIGNAL(clicked()), parent, SLOT(close()));
}

void DockTitleBarWidget::setTitle(const QString &title)
{
    label->setText(title);
}

DockTitleBarWidget::~DockTitleBarWidget()
{
}