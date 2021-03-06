/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef SYNCRUNFILELOG_H
#define SYNCRUNFILELOG_H

#include <QFile>
#include <QTextStream>
#include <QScopedPointer>

#include "mirall/syncfileitem.h"
#include "mirall/utility.h"

namespace Mirall {
class SyncFileItem;

class SyncRunFileLog
{
public:
    SyncRunFileLog();
    void start( const Utility::StopWatch &stopWatch );
    void logItem( const SyncFileItem& item );
    void close();

protected:

private:
    QString dateTimeStr( const QDateTime& dt );
    QString instructionToStr( csync_instructions_e inst );

    QScopedPointer<QFile> _file;
    QTextStream _out;
    bool        _start;

};
}

#endif // SYNCRUNFILELOG_H
