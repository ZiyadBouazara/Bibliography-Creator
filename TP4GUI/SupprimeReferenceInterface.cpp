/*
 * \file SupprimerReferenceInterface.cpp
 * \brief Interface de la classe supprimerreference
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#include "validationFormat.h"
#include "SupprimeReferenceInterface.h"
#include "QMessageBox"
#include "ctype.h"

using namespace util;


/*
 * \brief constructeur de la classe SupprimeReferenceInterface
 */
SupprimeReferenceInterface::SupprimeReferenceInterface ()
{
  widget.setupUi (this);
}


/*
 * \brief destructeur de la classe SupprimeReferenceInterface
 */
SupprimeReferenceInterface::~SupprimeReferenceInterface () { }


/*
 * \brief accesseur pour l'identifiant
 * \return l'identifiant de l'oeuvre
 */
std::string
SupprimeReferenceInterface::reqIdentifiant () const
{
  return widget.identifiant->text ().toStdString ();
}


/*
 * \brief méthode validant un identifiant
 * \return un booléen, si l'identifiant est valide
 */
bool
SupprimeReferenceInterface::entreeSontValide () const
{
  if (!(validerCodeIssn (reqIdentifiant ()) || validerCodeIsbn (reqIdentifiant ())))
    {
      return false;
    }
  return true;
}


/*
 * \brief méthode validant un enregistrement
 */
void
SupprimeReferenceInterface::valideEnregistrement ()
{
  if (!(validerCodeIssn (reqIdentifiant ()) || validerCodeIsbn (reqIdentifiant ())))
    {
      QString message ("Le code identifiant doit etre d'un format valide");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}