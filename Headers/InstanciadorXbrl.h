/****************************************************************************************
 * Copyright (c) 2012 Lucas Lira Gomes <x8lucas8x@gmail.com>                            *
 * Copyright (c) 2012 Raony Benjamim <raonybenjamim@gmail.com>                          *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 2 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#ifndef INSTANCIADORXBRL_H
#define INSTANCIADORXBRL_H

#include <QList>
#include <QObject>

class Aih;
class Procedimento;
class GeradorEstatistica;

class QFile;
class QXmlStreamWriter;

class InstanciadorXbrl : public QObject
{
Q_OBJECT

public:
    explicit InstanciadorXbrl( QString caminhoXml,
                               GeradorEstatistica *geradorEstatistica,
                               QString caminhoTaxonomia,
                               QObject *parent );
    virtual ~InstanciadorXbrl();

    bool criarXml();
    void preencherXbrl();

signals:
    void xbrlPreenchido( QString );

private:
    QFile *m_arquivoXml;
    QString m_caminhoTaxonomia;
    QXmlStreamWriter *m_xmlStream;
    GeradorEstatistica *m_geradorEstatistica;
};

#endif // INSTANCIADORXBRL_H
