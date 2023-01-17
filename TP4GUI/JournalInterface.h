/*
 * \file JournalInterface.h
 * \brief Interface de la classe journal
 * \author Equipe 14
 * \date 2022-11-28
 *
 */

#ifndef _JOURNALINTERFACE_H
#define _JOURNALINTERFACE_H

#include "ui_JournalInterface.h"

/*
 * \brief Classe JournalInterface
 */
class JournalInterface : public QDialog
{
  Q_OBJECT
public:
  JournalInterface ();
  virtual ~JournalInterface ();
  std::string reqAuteurs () const;
  std::string reqTitre () const;
  int reqAnnee () const;
  std::string reqIdentifiant () const;
  std::string reqNom () const;
  int reqVolume () const;
  int reqNumero () const;
  int reqPage () const;
  bool entreeSontValide () const;

private slots:
  void valideEnregistrement ();

private:
  Ui::JournalInterface widget;
};

#endif /* _JOURNALINTERFACE_H */
