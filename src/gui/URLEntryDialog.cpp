#include "gui/URLEntryDialog.hpp"

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
URLEntryDialog::URLEntryDialog(WindowController *controller, Glib::RefPtr<Gtk::Builder> builder)
{
    m_controller = controller;

    //Get the dialog itself
    builder->get_widget("open_dialog", m_dialog);
    if(m_dialog == nullptr)
    {
        std::cerr << "Failed to find the open_dialog" << std::endl;
    }

    //Get the text entry widget
    builder->get_widget("url_entry_open_dialog", m_entry);
    if(m_entry == nullptr)
    {
        std::cerr << "Failed to find the url entry" << std::endl;
    }

    //Get the open button and set up signal handler
    builder->get_widget("open_button_open_dialog", m_open);
    if(m_open)
    {
        //Set up the signal handler
        m_open->signal_clicked().connect(sigc::mem_fun(*this, &URLEntryDialog::on_open));
    }
    else
    {
        std::cerr << "Failed to find the open button" << std::endl;
    }

    //Get the cancel button and set up handler
    builder->get_widget("cancel_button_open_dialog", m_cancel);
    if(m_cancel)
    {
        //set up the signal handler
        m_cancel->signal_clicked().connect(sigc::mem_fun(*this, &URLEntryDialog::on_cancel));
    }
    else
    {
        std::cerr << "Failed to find the cancel button" << std::endl;
    }

    //Show the dialog window
    m_dialog->show();
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
URLEntryDialog::~URLEntryDialog()
{

}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void URLEntryDialog::on_open()
{
    //Tell the window controller to open the media
    m_controller->open_media(m_entry->get_text()); 
    //Close the dialog box
    m_dialog->close();
}

/**********************************************************
 * Function: 	
 *
 * Description: 
 *
 * Arguments:	
 * 				
 * 
 * Returns:		
 *
**********************************************************/
void URLEntryDialog::on_cancel()
{
    //If the dialog is not null, close the dialog
    if(m_dialog != nullptr)
    {
        m_dialog->close();
    }
}
