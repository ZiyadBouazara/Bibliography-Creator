/*
 * \file JournalTesteur.cpp
 * \brief Fichier contenant les tests de la classe Journal
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
 * \brief Test du constructeur Journal::Journal(const std::string& p_auteurs, const std::string& p_titre,
            const unsigned int& p_annee, const std::string& p_identifiant,
            const std::string& p_nom, const unsigned int& p_volume,
            const unsigned int& p_numero, const unsigned int& p_page) \n
 * cas valide : \n
 * ConstructeurValide : Les parametres de la reference Journal sont valide. \n
 * cas invalide : \n
 * aucun.
 */

TEST (Journal, ConstructeurValide)
{
  Journal unJournal ("Emilio Lemus", "This is a journal", 2022, "ISSN 1937-4771", "Math Ingenieur II", 24, 6, 113);
  ASSERT_EQ ("Emilio Lemus. This is a journal. Math Ingenieur II, vol. 24, no. 6, pp. 113, 2022. ISSN 1937-4771.", unJournal.reqReferenceFormate ());
}

/*
 * \class JournalValide
 * \brief Fixture JournalValide pour la creation d'un objet Journal valide pour les tests.
 */

class JournalValide : public ::testing::Test
{

public:


  JournalValide () : t_journal ("Charlie Chap", "The return of KING KONG", 2000, "ISSN 1467-8640", "Emilio", 44, 10, 31) { }
  Journal t_journal;
} ;


/*
 * \brief Test de la methode Journal::reqNom() \n
 * cas valide : \n
 * reqNom : verifier que le retour est belle et bien le nom de la revue. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (JournalValide, reqNom)
{
  ASSERT_EQ ("Emilio", t_journal.reqNom ());
}


/*
 * \brief Test de la methode Journal::reqVolume() \n
 * cas valide : \n
 * reqVolume : verifier que le retour est belle et bien le volume de la revue. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (JournalValide, reqVolume)
{
  ASSERT_EQ (44, t_journal.reqVolume ());
}


/*
 * \brief Test de la methode Journal::reqNumero() \n
 * cas valide : \n
 * reqNumero : verifier que le retour est belle et bien le numero de la revue. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (JournalValide, reqNumero)
{
  ASSERT_EQ (10, t_journal.reqNumero ());
}


/*
 * \brief Test de la methode Journal::reqPage() \n
 * cas valide : \n
 * reqPage : verifier que le retour est belle et bien la page de la revue. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (JournalValide, reqPage)
{
  ASSERT_EQ (31, t_journal.reqPage ());
}


/*
 * \brief Test de la methode Journal::reqReferenceFormate() \n
 * cas valide : \n
 * reqReferenceFormate : verifie le retour du formatage d'une reference de type journal. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (JournalValide, reqReferenceFormate)
{
  ASSERT_EQ ("Charlie Chap. The return of KING KONG. Emilio, vol. 44, no. 10, pp. 31, 2000. ISSN 1467-8640.", t_journal.reqReferenceFormate ());
}


/*
 * \brief Test de la methode Journal::clone() \n
 * cas valide : \n
 * cloneValid : verifie que le retour sois un nouvel objet Journal identique a celui cloner. \n
 * cas invalide : \n
 * aucun.
 */

TEST_F (JournalValide, cloneValid)
{

  Reference* myClone = t_journal.clone ();

  ASSERT_EQ (myClone->reqAuteurs (), t_journal.reqAuteurs ());
  ASSERT_EQ (myClone->reqTitre (), t_journal.reqTitre ());
  ASSERT_EQ (myClone->reqAnnee (), t_journal.reqAnnee ());
  ASSERT_EQ (myClone->reqIdentifiant (), t_journal.reqIdentifiant ());
  ASSERT_EQ (myClone->reqReferenceFormate (), t_journal.reqReferenceFormate ());


  delete myClone;
}