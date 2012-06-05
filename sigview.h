/*
 * This file is part of the sigrok project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef SIGVIEW_H
#define SIGVIEW_H

#include <QtOpenGL/QGLWidget>
#include <QTimer>

class SigSession;

class SigView : public QGLWidget
{
	Q_OBJECT

private:
	static const int SignalHeight;

public:
	explicit SigView(SigSession &session, QWidget *parent = 0);

protected:

	void initializeGL();

	void resizeGL(int width, int height);

	void paintGL();

private slots:
	void dataUpdated();

private:
	SigSession &_session;

	uint64_t _scale;
	int64_t _offset;
};

#endif // SIGVIEW_H
