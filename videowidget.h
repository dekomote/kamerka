/*
 * Copyright (c) Özkan Pakdil <ozkan.pakdil@gmail.com>
 * Copyright (c) Sebastian Krzyszkowiak <dos@dosowisko.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 (or higher) of the License
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtDeclarative>
#include <phonon/MediaObject>

#include "capturethread.h"

class videowidget : public QWidget
{
Q_OBJECT
  public:
    videowidget(QWidget *parent = 0);
    ~videowidget();

    QPixmap pixmap;
    CaptureThread thread;
    QDeclarativeView *ui;
    Phonon::MediaObject* media;
    void setFileName(QString);
    void setDeviceName(QString);
  protected:
    void paintEvent(QPaintEvent *event);

  public slots:
    void setPicture(QImage);
};

class Focia : public QObject {
Q_OBJECT
  public:
    QString filename;
    void setFilename(QString);
  public slots:
    void openFile(unsigned int);
};

#endif // VIDEOWIDGET_H
