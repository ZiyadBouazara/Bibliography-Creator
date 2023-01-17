/*
 * \file JournalInterface.cpp
 * \brief Interface de la classe journal
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#include "JournalInterface.h"
#include "validationFormat.h"
#include "QMessageBox"

using namespace util;


/*
 * \brief constructeur de la classe JournalInterface
 */
JournalInterface::JournalInterface ()
{
  widget.setupUi (this);
}


/*
 * \brief destructeur de la classe JournalInterface
 */
JournalInterface::~JournalInterface () { }


/*
 * \brief accesseur pour les auteurs
 * \return les auteurs du journal
 */
std::string
JournalInterface::reqAuteurs () const
{
  return widget.auteurs->text ().toStdString ();
}


/*
 * \brief accesseur pour le titre
 * \return le titre du journal
 */
std::string
JournalInterface::reqTitre () const
{
  return widget.titre->text ().toStdString ();
}


/*
 * \brief accesseur pour l'année
 * \return l'année du journal
 */
int
JournalInterface::reqAnnee () const
{
  return widget.annee->text ().toInt ();
}


/*
 * \brief accesseur pour l'identifiant
 * \return l'identifiant du journal
 */
std::string
JournalInterface::reqIdentifiant () const
{
  return widget.identifiant->text ().toStdString ();
}


/*
 * \brief accesseur pour le nom du journal
 * \return le nom du journal
 */
std::string
JournalInterface::reqNom () const
{
  return widget.nom->text ().toStdString ();
}


/*
 * \brief accesseur pour le volume du journal
 * \return le volume du journal
 */
int
JournalInterface::reqVolume () const
{
  return widget.volume->text ().toInt ();
}


/*
 * \brief accesseur pour le numéro du journal
 * \return le numéro du journal
 */
int
JournalInterface::reqNumero () const
{
  return widget.numero->text ().toInt ();
}


/*
 * \brief accesseur pour le nombre de page du journal
 * \return le nombre de page du journal
 */
int
JournalInterface::reqPage () const
{
  return widget.page->text ().toInt ();
}


/*
 * \brief méthode vérifiant si les entrées sont valides
 * \return un booléen, si les valeurs sont bonnes ou non
 */
bool
JournalInterface::entreeSontValide () const
{


  if (!validerFormatNom (reqAuteurs ()) &&
      !validerFormatNom (reqTitre ()) &&
      reqNom ().empty () &&
      reqVolume () <= 0 &&
      reqNumero () <= 0 &&
      reqNumero () <= 0 &&
      reqAnnee () <= 0 &&
      !(validerCodeIssn (reqIdentifiant ()) && !validerCodeIsbn (reqIdentifiant ())))
    {
      return false;
    }
  return true;
}


/*
 * \brief méthode validant l'enregistrement du journal
 */
void
JournalInterface::valideEnregistrement ()
{
  if (!validerFormatNom (reqAuteurs ()))
    {
      QString message ("Le nom d'auteurs est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (!validerFormatNom (reqTitre ()))
    {
      QString message ("Le titre est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (reqNom ().empty ())
    {
      QString message ("Le nom ne peux pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (reqAnnee () <= 0)
    {
      QString message ("L'anne est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (reqVolume () <= 0)
    {
      QString message ("Le volume est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (reqPage () <= 0)
    {
      QString message ("La page est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (reqNumero () <= 0)
    {
      QString message ("Le numero est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (!(validerCodeIssn (reqIdentifiant ()) && !validerCodeIsbn (reqIdentifiant ())))
    {
      QString message ("Le code identifiant doit etre d'un format valide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}


