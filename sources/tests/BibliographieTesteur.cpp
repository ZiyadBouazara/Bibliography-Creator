/*
 * \file BibliographieTesteur.cpp
 * \brief Fichier contenant les tests de la classe bibliographie
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#include <gtest/gtest.h>
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
#include "ReferenceException.h"
#include <sstream>

using namespace std;
using namespace biblio;


/*
 * \brief Test du constructeur Bibliographie::Bibliographie(const string& p_nomBibliographie) \n
 * cas valide : \n
 * ConstructeurValide : Le parametre du nom de la bibliographie est valide. \n
 * cas invalide : \n
 * aucun (il n'y a pas de contrainte pour le nom de la bibliographie).
 */

TEST (Bibliographie, ConstructeurValid)
{

  Bibliographie maBibliographie ("Favorie");
  ASSERT_EQ ("Favorie", maBibliographie.reqNomBibliographie ());

}

/*
 * \class BibliographieValide
 * \brief Fixture BibliographieValide pour la creation d'un objet Bibliographie
 *  valide, contenant un objet Ouvrage valide pour les tests.
 */

class BibliographieValide : public ::testing::Test
{

public:


  BibliographieValide () :
  t_bibliographie ("Mes favoris"),
  t_ouvrage ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3", "Springer", "New York")
  {
    t_bibliographie.ajouterReference (t_ouvrage);
  }
  Bibliographie t_bibliographie;
  Ouvrage t_ouvrage;
} ;


/*
 * \brief Test du constructeur Bibliographie::Bibliographie(const Bibliographie& p_bibliographie) \n
 * cas valide : \n
 * ConstructeurCopieValide : Un constructeur de copie valide. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (BibliographieValide, ConstructeurCopieValide)
{
  Bibliographie uneCopie (t_bibliographie);
  ASSERT_EQ (t_bibliographie.reqNomBibliographie (), uneCopie.reqNomBibliographie ());
  ASSERT_EQ (t_bibliographie.reqBibliographieFormate (), uneCopie.reqBibliographieFormate ());
}


/*
 * \brief Test de la methode Bibliographie::operator=(const Bibliographie& p_bibliographie) \n
 * cas valide : \n
 * operateurAssignation : verifie que le processus d'assignation d'une bibliographie a une autre sois bon. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (BibliographieValide, operateurAssignation)
{
  Bibliographie maBiblio ("Not my favorits");
  Journal monJournal ("Charlie Chap", "The return of KING KONG", 2000, "ISSN 1467-8640", "Emilio", 44, 10, 31);
  maBiblio.ajouterReference (monJournal);

  ASSERT_FALSE (maBiblio.reqBibliographieFormate () == t_bibliographie.reqBibliographieFormate ());

  maBiblio = t_bibliographie;

  ASSERT_EQ (maBiblio.reqNomBibliographie (), t_bibliographie.reqNomBibliographie ());
  ASSERT_EQ (maBiblio.reqBibliographieFormate (), t_bibliographie.reqBibliographieFormate ());
}


/*
 * \brief Test de la methode Bibliographie::reqNomBibliographie() \n
 * cas valide : \n
 * reqNomBibliographie : verifier que le retour est belle et bien le nom de la bibliographie. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (BibliographieValide, reqNomBibliographie)
{
  ASSERT_EQ ("Mes favoris", t_bibliographie.reqNomBibliographie ());
}


/*
 * \brief Test de la methode Bibliographie::ajouterReference(const biblio::Reference& p_nouvelleReference) \n
 * cas valide : \n
 * ajouterReferenceNonPresent : ajoute une reference au vecteur de Bibliographie. \n
 * ajouterReferenceDejaPresent : ajoute pas la reference au vecteur de Bibliographie car celle si est deja presente. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (BibliographieValide, ajouterReferenceDejaPresent)
{

  Ouvrage unOuvrage ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3", "Springer", "New York");

  ASSERT_THROW (t_bibliographie.ajouterReference (unOuvrage), ReferenceDejaPresenteException) << "Probleme doublon non detecte";
}


TEST_F (BibliographieValide, ajouterReferenceNonPresent)
{

  Journal t_journal ("Emilio Lemus", "This is a journal", 2022, "ISSN 1937-4771", "Miguel Lemus", 39, 44, 10);

  t_bibliographie.ajouterReference (t_journal);

  stringstream output;
  output << t_bibliographie.reqNomBibliographie () << "\n" << "==============================="
          << "\n" << "[1] " << t_ouvrage.reqReferenceFormate () << "\n"
          << "[2] " << t_journal.reqReferenceFormate () << "\n";

  ASSERT_EQ (output.str (), t_bibliographie.reqBibliographieFormate ());
}


/*
 * \brief Test de la methode Bibliographie::reqBibliographieFormate() \n
 * cas valide : \n
 * reqBibliographieFormate : verifie le retour du formatage d'une bibliographie. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (BibliographieValide, reqBibliographieFormate)
{
  Journal t_journal ("Emilio Lemus", "This is a journal", 2022, "ISSN 1937-4771", "Miguel Lemus", 39, 44, 10);

  t_bibliographie.ajouterReference (t_journal);

  stringstream output;
  output << t_bibliographie.reqNomBibliographie () << "\n" << "==============================="
          << "\n" << "[1] " << t_ouvrage.reqReferenceFormate () << "\n"
          << "[2] " << t_journal.reqReferenceFormate () << "\n";

  ASSERT_EQ (output.str (), t_bibliographie.reqBibliographieFormate ());
}


TEST_F (BibliographieValide, SupprimerReferenceExistante)
{
  t_bibliographie.supprimerReference (t_ouvrage.reqIdentifiant ());
  ASSERT_EQ ("Mes favoris\n===============================\n", t_bibliographie.reqBibliographieFormate ());
}


TEST_F (BibliographieValide, SupprimerReferenceInexistante)
{
  ASSERT_THROW (t_bibliographie.supprimerReference ("ISBN 978-0-387-77591-4"), ReferenceAbsenteException) << "Probleme doublon non detecte";
}