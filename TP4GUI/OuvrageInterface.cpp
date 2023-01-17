/*
 * \file OuvrageInterface.cpp
 * \brief Interface de la classe ouvrage
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#include "OuvrageInterface.h"
#include "validationFormat.h"
#include "QMessageBox"

using namespace util;


/*
 * \brief constructeur de la classe OuvrageInterface
 */
OuvrageInterface::OuvrageInterface ()
{
  widget.setupUi (this);
}


/*
 * \brief destructeur de la classe OuvrageInterface
 */
OuvrageInterface::~OuvrageInterface () { }


/*
 * \brief accesseur pour les auteurs
 * \return les auteurs de l'ouvrage
 */
std::string
OuvrageInterface::reqAuteurs () const
{
  return widget.auteurs->text ().toStdString ();
}


/*
 * \brief accesseur pour le titre
 * \return le titre de l'ouvrage
 */
std::string
OuvrageInterface::reqTitre () const
{
  return widget.titre->text ().toStdString ();
}


/*
 * \brief accesseur pour l'année
 * \return l'année de l'ouvrage
 */
int
OuvrageInterface::reqAnnee () const
{
  return widget.annee->text ().toInt ();
}


/*
 * \brief accesseur pour l'identifiant
 * \return l'identifiant de l'oeuvre
 */
std::string
OuvrageInterface::reqIdentifiant () const
{
  return widget.identifiant->text ().toStdString ();
}


/*
 * \brief accesseur pour l'éditeur
 * \return l'éditeur du journal
 */
std::string
OuvrageInterface::reqEditeur () const
{
  return widget.editeur->text ().toStdString ();
}


/*
 * \brief accesseur pour la ville
 * \return la ville du journal
 */
std::string
OuvrageInterface::reqVille () const
{
  return widget.ville->text ().toStdString ();
}


/*
 * \brief méthode vérifiant si les entrées sont valides
 * \return un booléen, si les valeurs sont bonnes ou non
 */
bool
OuvrageInterface::entreeSontValide () const
{
  if (!validerFormatNom (reqAuteurs ()) &&
      !validerFormatNom (reqTitre ()) &&
      !validerFormatNom (reqEditeur ())&&
      !validerFormatNom (reqVille ()) &&
      reqAnnee () <= 0 &&
      !(!validerCodeIssn (reqIdentifiant ()) && validerCodeIsbn (reqIdentifiant ())))
    {
      return false;
    }
  return true;
}


/*
 * \brief méthode validant l'enregistrement du journal
 */
void
OuvrageInterface::valideEnregistrement ()
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
  else if (!validerFormatNom (reqEditeur ()))
    {
      QString message ("Le nom d'editeur est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (reqAnnee () <= 0)
    {
      QString message ("L'anne est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (!validerFormatNom (reqVille ()))
    {
      QString message ("La ville est invalide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else if (!(!validerCodeIssn (reqIdentifiant ()) && validerCodeIsbn (reqIdentifiant ())))
    {
      QString message ("Le code identifiant doit etre d'un format valide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}