/*
 * \file OuvrageTesteur.cpp
 * \brief Fichier contenant les tests de la classe Ouvrage
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#include <gtest/gtest.h>
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
#include <sstream>

using namespace std;
using namespace biblio;


/*
 * \brief Test du constructeur Ouvrage::Ouvrage(const std::string& p_auteurs, const std::string& p_titre,
            const unsigned int& p_annee, const std::string& p_identifiant,
            const std::string& p_editeur, const std::string& p_ville) \n
 * cas valide : \n
 * ConstructeurValide : Les parametres de l'Ouvrage sont valide selong critere etablit. \n
 * cas invalide : \n
 * aucun.
 */

TEST (Ouvrage, ConstructeurValide)
{
  Ouvrage myOuvrage ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3", "Springer", "New York");

  ostringstream output;
  output << myOuvrage.reqAuteurs () << ". " << myOuvrage.reqTitre () << ". "
          << myOuvrage.reqVille () << " : " << myOuvrage.reqEditeur ()
          << ", " << myOuvrage.reqAnnee () << ". " << myOuvrage.reqIdentifiant () << ".";

  ASSERT_EQ (output.str (), myOuvrage.reqReferenceFormate ());
}

/*
 * \class OuvrageValide
 * \brief Fixture OuvrageValide pour la creation d'un objet Ouvrage valide pour les tests.
 */

class OuvrageValide : public ::testing::Test
{

public:


  OuvrageValide () : t_ouvrage ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3", "Springer", "New York") { }
  Ouvrage t_ouvrage;
} ;


/*
 * \brief Test de la methode Ouvrage::reqEditeur() \n
 * cas valide : \n
 * reqEditeur : verifier que le retour est belle et bien l'editeur de l'ouvrage. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (OuvrageValide, reqEditeur)
{
  ASSERT_EQ ("Springer", t_ouvrage.reqEditeur ());
}


/*
 * \brief Test de la methode Ouvrage::reqVille() \n
 * cas valide : \n
 * reqVille : verifier que le retour est belle et bien la ville d'edition de l'ouvrage. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (OuvrageValide, reqVille)
{
  ASSERT_EQ ("New York", t_ouvrage.reqVille ());
}


/*
 * \brief Test de la methode Ouvrage::reqReferenceFormate() \n
 * cas valide : \n
 * reqReferenceFormate : verifie le retour du formatage d'une reference de type ouvrage. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (OuvrageValide, reqReferenceFormate)
{
  ostringstream output;
  output << t_ouvrage.reqAuteurs () << ". " << t_ouvrage.reqTitre () << ". "
          << t_ouvrage.reqVille () << " : " << t_ouvrage.reqEditeur ()
          << ", " << t_ouvrage.reqAnnee () << ". " << t_ouvrage.reqIdentifiant () << ".";

  ASSERT_EQ (output.str (), t_ouvrage.reqReferenceFormate ());
}


/*
 * \brief Test de la methode Ouvrage::clone() \n
 * cas valide : \n
 * clone : verifie que le retour sois un nouvel objet Ouvrage identique a celui cloner. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (OuvrageValide, clone)
{
  Reference* myClone = t_ouvrage.clone ();

  ASSERT_EQ (myClone->reqAuteurs (), t_ouvrage.reqAuteurs ());
  ASSERT_EQ (myClone->reqTitre (), t_ouvrage.reqTitre ());
  ASSERT_EQ (myClone->reqAnnee (), t_ouvrage.reqAnnee ());
  ASSERT_EQ (myClone->reqIdentifiant (), t_ouvrage.reqIdentifiant ());
  ASSERT_EQ (myClone->reqReferenceFormate (), t_ouvrage.reqReferenceFormate ());

  delete myClone;
}