/*
 * \file ReferenceTesteur.cpp
 * \brief Fichier contenant les test sur la classe Reference
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#include <gtest/gtest.h>
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
#include "Reference.h"
#include "validationFormat.h"
#include <sstream>

using namespace std;
using namespace biblio;

/*
 * \class ReferenceTesteur
 * \brief Fixture ReferenceTesteur pour pouvoir tester le constructeur car la classe Reference est virtuel pur.
 */

class ReferenceTesteur : public Reference
{

public:


  ReferenceTesteur (const std::string& p_auteurs, const std::string& p_titre, const unsigned int& p_annee, const std::string& p_identifiant)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant) { }


  virtual const string
  reqReferenceFormate () const
  {
    return Reference::reqReferenceFormate ();
  }


  virtual Reference*
  clone () const
  {
    return nullptr;
  }


} ;


/*
 * \brief Test du constructeur Reference::Reference(const std::string& p_auteurs, const std::string& p_titre, const unsigned int& p_annee, const std::string& p_identifiant) \n
 * cas valide : \n
 * ConstructeurValide : Les parametres de la reference sont valide selon les critaire etabli. \n
 * cas invalide : \n
 * aucun.
 */

TEST (Reference, ConstructeurValide)
{
  ReferenceTesteur refTest ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3");

  ASSERT_EQ ("Steven Spielberg", refTest.reqAuteurs ());
  ASSERT_EQ ("The Titanic", refTest.reqTitre ());
  ASSERT_EQ (1997, refTest.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", refTest.reqIdentifiant ());
}

/*
 * \class ReferenceValide
 * \brief Fixture ReferenceValide pour la creation d'un objet Reference valide pour effectuer des tests.
 */

class ReferenceValide : public ::testing::Test
{

public:


  ReferenceValide () : t_ref ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3") { };
  ReferenceTesteur t_ref;
} ;


/*
 * \brief Test de la methode Reference::reqAuteurs() \n
 * cas valide : \n
 * reqAuteurs : verifier que le retour est belle et bien l'auteur de la reference. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (ReferenceValide, reqAuteurs)
{
  ASSERT_EQ ("Steven Spielberg", t_ref.reqAuteurs ());
}


/*
 * \brief Test de la methode Reference::reqTitre() \n
 * cas valide : \n
 * reqTitre : verifier que le retour est belle et bien le titre de la reference. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (ReferenceValide, reqTitre)
{
  ASSERT_EQ ("The Titanic", t_ref.reqTitre ());
}


/*
 * \brief Test de la methode Reference::reqAnnee() \n
 * cas valide : \n
 * reqAnnee : verifier que le retour est belle et bien l'annee de la reference. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (ReferenceValide, reqAnnee)
{
  ASSERT_EQ (1997, t_ref.reqAnnee ());
}


/*
 * \brief Test de la methode Reference::reqIdentifiant() \n
 * cas valide : \n
 * reqIdentifiant : verifier que le retour est belle et bien l'identifiant de la reference. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (ReferenceValide, reqIdentifiant)
{
  ASSERT_EQ ("ISBN 978-0-387-77591-3", t_ref.reqIdentifiant ());
}


/*
 * \brief Test de la methode Reference::asgAnnee(const unsigned int& p_annee) \n
 * cas valide : \n
 * asgAnneeValid : assigne une nouvelle anner de publication qui respect les criteres etablit. \n
 * asgAnneeInvalid : n'assigne pas la nouvelle anner car celle-ci ne respect pas les criteres etablit. \n
 * cas invalide: \n
 * aucun.
 */

TEST_F (ReferenceValide, asgAnneeValid)
{

  t_ref.asgAnnee (2022);
  ASSERT_EQ (2022, t_ref.reqAnnee ());
  ASSERT_TRUE (t_ref.reqAnnee () > 0);
}


TEST_F (ReferenceValide, asgAnneeInvalid)
{

  ASSERT_THROW (t_ref.asgAnnee (0), PreconditionException)
          << "Annee invalide elle doit etre superieur a 0";
}


/*
 * \brief Test de la methode Reference::reqReferenceFormate() \n
 * cas valide : \n
 * reqReferenceFormate : verifie le retour du formatage d'une reference. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (ReferenceValide, reqReferenceFormate)
{
  ASSERT_EQ ("Steven Spielberg. The Titanic.", t_ref.reqReferenceFormate ());
}


/*
 * \brief Test de la methode Reference::operator==(const Reference& p_reference) \n
 * cas valide : \n
 * operateurEgalValid : verifie l'egaliter entre deux objet Reference avec des atribues identique. \n
 * operateurEgalInvalid : verifie l'inegaliter de deux objet Reference avec des atribues different. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (ReferenceValide, operateurEgalValid)
{
  ReferenceTesteur otherRef ("Steven Spielberg", "The Titanic", 1997, "ISBN 978-0-387-77591-3");
  ASSERT_TRUE (t_ref == otherRef);
}


TEST_F (ReferenceValide, operateurEgalInvalid)
{
  ReferenceTesteur otherRef ("Not Steven Spielberg", "Not The Titanic", 2002, "ISBN 978-0-387-77591-3");
  ASSERT_FALSE (t_ref == otherRef);
}
