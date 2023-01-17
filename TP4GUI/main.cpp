/*
 * \file main.cpp
 * \brief main du programme TP4, l'outil de référence bibliographique
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#include <QApplication>
#include "BibliographieInterface.h"


int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here

  BibliographieInterface fenetrePrincipal;
  fenetrePrincipal.show ();

  return app.exec ();
}
