/*
 * \file BibliographieInterface.cpp
 * \brief Interface de la classe bibliographie
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#include "BibliographieInterface.h"
#include "JournalInterface.h"
#include "OuvrageInterface.h"
#include "SupprimeReferenceInterface.h"
#include "Bibliographie.h"
#include "Journal.h"
#include "Ouvrage.h"
#include "Reference.h"
#include "validationFormat.h"
#include "ReferenceException.h"
#include <QMessageBox>
#include <QFile>
#include <qtextstream.h>
#include <qt5/QtCore/qstring.h>
#include <iostream>
#include <sstream>

using namespace biblio;
using namespace util;


/*
 * \brief constructeur de la classe BibliographieInterface
 */
BibliographieInterface::BibliographieInterface ()
: m_biblio ("Ma Bibliographie")
{
  widget.setupUi (this);
  widget.affiche->setText (QString::fromStdString ( m_biblio.reqBibliographieFormate ()));
}


/*
 * \brief destructeur de la classe BibliographieInterface
 */
BibliographieInterface::~BibliographieInterface () { }


/*
 * \brief méthode ajouter une référence de type journal
 * \param[in] p_auteurs, le nom des auteurs
 * \param[in] p_titre, le titre du journal
 * \param[in] p_annee, l'annee de publication du journal
 * \param[in] p_identifiant, l'identifiant ISSN du journal
 * \param[in] p_nom, le nom du journal
 * \param[in] p_volume, le nom du volume du journal
 * \param[in] p_numero, le numero du journal
 * \param[in] p_page, le nombre de page du journal
 */
void
BibliographieInterface::ajouterJournal (const std::string& p_auteurs, const std::string& p_titre,
                                        const unsigned int& p_annee, const std::string& p_identifiant,
                                        const std::string& p_nom, const unsigned int& p_volume,
                                        const unsigned int& p_numero, const unsigned int& p_page)
{
  try
    {
      Journal myJournal (p_auteurs, p_titre, p_annee, p_identifiant, p_nom, p_volume, p_numero, p_page);
      m_biblio.ajouterReference (myJournal);
    }
  catch (ReferenceDejaPresenteException& e)
    {
      QString message = QString::fromStdString (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}


/*
 * \brief méthode ajouter une référence de type ouvrage
 * \param[in] p_auteurs, le nom des auteurs
 * \param[in] p_titre, le titre de l'oeuvre
 * \param[in] p_annee, l'annee de publication de l'oeuvre
 * \param[in] p_identifiant, l'identifiant ISBN de l'oeuvre
 * \param[in] p_editeur, l'editeur de l'oeuvre
 * \param[in] p_ville, la ville d'édition de l'oeuvre
 */
void
BibliographieInterface::ajouterOuvrage (const std::string& p_auteurs, const std::string& p_titre,
                                        const unsigned int& p_annee, const std::string& p_identifiant,
                                        const std::string& p_editeur, const std::string& p_ville)
{
  try
    {
      Ouvrage myOuvrage (p_auteurs, p_titre, p_annee, p_identifiant, p_editeur, p_ville);
      m_biblio.ajouterReference (myOuvrage);
    }
  catch (ReferenceDejaPresenteException& e)
    {
      QString message = QString::fromStdString (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}


/*
 * \brief méthode pour supprimer une reference de la bibliographie
 * \parma[in] p_identifiant, l'identifiant ISSN ou ISBN d'une référence
 */
void
BibliographieInterface::supprimeReference (const std::string& p_identifiant)
{
  try
    {
      m_biblio.supprimerReference (p_identifiant);
    }
  catch (ReferenceAbsenteException& e)
    {
      QString message = QString::fromStdString (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}


/*
 * \brief méthode permettant d'afficher une boite de dialogue pour entrer les parametres d'une référence de type journal
 */
void
BibliographieInterface::dialogJournal ()
{
  JournalInterface monJournalInterface;
  monJournalInterface.exec ();

  if (monJournalInterface.entreeSontValide ())
    {
      ajouterJournal (monJournalInterface.reqAuteurs (),
                      monJournalInterface.reqTitre (),
                      monJournalInterface.reqAnnee (),
                      monJournalInterface.reqIdentifiant (),
                      monJournalInterface.reqNom (),
                      monJournalInterface.reqVolume (),
                      monJournalInterface.reqNumero (),
                      monJournalInterface.reqPage () );

      widget.affiche->setText (QString::fromStdString ( m_biblio.reqBibliographieFormate ()));
    }
}


/*
 * \brief méthode permettant d'afficher une boite de dialogue pour entrer les parametres d'une référence de type ouvrage
 */
void
BibliographieInterface::dialogOuvrage ()
{
  OuvrageInterface monOuvrageInterface;
  monOuvrageInterface.exec ();

  if (monOuvrageInterface.entreeSontValide ())
    {
      ajouterOuvrage (monOuvrageInterface.reqAuteurs (),
                      monOuvrageInterface.reqTitre (),
                      monOuvrageInterface.reqAnnee (),
                      monOuvrageInterface.reqIdentifiant (),
                      monOuvrageInterface.reqEditeur (),
                      monOuvrageInterface.reqVille ());

      widget.affiche->setText (QString::fromStdString ( m_biblio.reqBibliographieFormate ()));
    }
}


/*
 * \brief méthode permettant d'afficher une boite de dialogue supprimer une référence
 */
void
BibliographieInterface::dialogSupprime ()
{
  SupprimeReferenceInterface supprimeRefInterface;
  supprimeRefInterface.exec ();

  if (supprimeRefInterface.entreeSontValide ())
    {
      supprimeReference (supprimeRefInterface.reqIdentifiant ());

      widget.affiche->setText (QString::fromStdString ( m_biblio.reqBibliographieFormate ()));
    }
}