/*
 * Copyright (c) 2012 Meltytech, LLC
 * Author: Dan Dennedy <dan@dennedy.org>
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
 */

#include "isingwidget.h"
#include "ui_isingwidget.h"

IsingWidget::IsingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IsingWidget)
{
    ui->setupUi(this);
}

IsingWidget::~IsingWidget()
{
    delete ui;
}

void IsingWidget::on_tempDial_valueChanged(int value)
{
    ui->tempSpinner->setValue(value/100.0);
}

void IsingWidget::on_tempSpinner_valueChanged(double value)
{
    ui->tempDial->setValue(value * 100);
}

void IsingWidget::on_borderGrowthDial_valueChanged(int value)
{
    ui->borderGrowthSpinner->setValue(value/100.0);    
}

void IsingWidget::on_borderGrowthSpinner_valueChanged(double value)
{
    ui->borderGrowthDial->setValue(value * 100);
}

void IsingWidget::on_spontGrowthDial_valueChanged(int value)
{
    ui->spontGrowthSpinner->setValue(value/100.0);
}

void IsingWidget::on_spontGrowthSpinner_valueChanged(double value)
{
    ui->spontGrowthDial->setValue(value * 100);
}

Mlt::Properties* IsingWidget::mltProperties()
{
    Mlt::Properties* p = new Mlt::Properties;
    p->set("Temperature", ui->tempSpinner->text().toAscii().constData());
    p->set("Border Growth", ui->borderGrowthSpinner->text().toAscii().constData());
    p->set("Spontaneous Growth", ui->spontGrowthSpinner->text().toAscii().constData());
    return p;
}

void IsingWidget::load(Mlt::Properties& p)
{
    ui->tempSpinner->setValue(p.get_double("Temperature"));
    ui->borderGrowthSpinner->setValue(p.get_double("Border Growth"));
    ui->spontGrowthSpinner->setValue(p.get_double("Spontaneous Growth"));
}
