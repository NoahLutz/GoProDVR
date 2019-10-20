#include "gui/SeekBar.hpp"

#define MINIMUM_HEIGHT 50
#define MINIMUM_WIDTH 400

#define NATURAL_HEIGHT 60
#define NATURAL_WIDTH 450


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
SeekBar::SeekBar():
    Glib::ObjectBase("seekbar"),
    Gtk::Widget(),
    m_scale_prop(*this, "example scale", 500),
    m_scale(1000)
{
    set_has_window(true);
    set_name("SeekBar");

    m_refCssProvider = Gtk::CssProvider::create();
    auto refStyleContext = get_style_context();
    refStyleContext->add_provider(m_refCssProvider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    m_refCssProvider->signal_parsing_error().connect(sigc::mem_fun(*this, &SeekBar::on_parsing_error));

    try
    {
        m_refCssProvider->load_from_path("custom_gtk.css");
    }
    catch(const Gtk::CssProviderError& ex)
    {
        std::cerr << "CssProviderError, Gtk::CssProvider::load_from_path() failed: " << ex.what() << std::endl;
    }
    catch(const Glib::Error& ex)
    {
        std::cerr << "Error, Gtk::CssProvider::load_from_path() failed: " << ex.what() << std::endl;
    }
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
SeekBar::~SeekBar()
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
void SeekBar::on_parsing_error(const Glib::RefPtr<const Gtk::CssSection>& section, const Glib::Error& error)
{
    std::cerr << "on_parsing_error(): " << error.what() << std::endl;
    if(section)
    {
        const auto file = section->get_file();
        if(file)
        {
            std::cerr << " URI = " << file->get_uri() << std::endl;
        }
    }
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
Gtk::SizeRequestMode SeekBar::get_request_mode_vfunc() const
{
    return Gtk::Widget::get_request_mode_vfunc();
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
void SeekBar::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
{
    minimum_width = MINIMUM_WIDTH;
    natural_width = NATURAL_WIDTH;
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
void SeekBar::get_preferred_height_for_width_vfunc(int width, int& minimum_height, int& natural_height) const
{
    minimum_height = MINIMUM_HEIGHT;
    natural_height = NATURAL_HEIGHT;
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
void SeekBar::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
{
    minimum_height = MINIMUM_HEIGHT;
    natural_height = NATURAL_HEIGHT;
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
void SeekBar::get_preferred_width_for_height_vfunc(int height, int& minimum_width, int& natural_width) const
{
    minimum_width = MINIMUM_WIDTH;
    natural_width = NATURAL_WIDTH;
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
void SeekBar::on_size_allocate(Gtk::Allocation& allocation)
{
    set_allocation(allocation);
    if(m_refGdkWindow)
    {
        m_refGdkWindow->move_resize(allocation.get_x(), allocation.get_y(), allocation.get_width(), allocation.get_height());
    }
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
void SeekBar::on_map()
{
    Gtk::Widget::on_map();
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
void SeekBar::on_unmap()
{
    Gtk::Widget::on_unmap();
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
void SeekBar::on_realize()
{
    set_realized();
    
    m_scale = m_scale_prop.get_value();

    if(!m_refGdkWindow)
    {
        GdkWindowAttr attributes;
        memset(&attributes, 0, sizeof(attributes));

        Gtk::Allocation allocation = get_allocation();

        attributes.x = allocation.get_x();
        attributes.y = allocation.get_y();
        attributes.width = allocation.get_width();
        attributes.height = allocation.get_height();

        attributes.event_mask = get_events() | Gdk::EXPOSURE_MASK;
        attributes.window_type = GDK_WINDOW_CHILD;
        attributes.wclass = GDK_INPUT_OUTPUT;

        m_refGdkWindow = Gdk::Window::create(get_parent_window(), &attributes, GDK_WA_X | GDK_WA_Y);
        set_window(m_refGdkWindow);

        m_refGdkWindow->set_user_data(gobj());
    }
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
void SeekBar::on_unrealize()
{
    m_refGdkWindow.reset();

    Gtk::Widget::on_unrealize();
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
bool SeekBar::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    const Gtk::Allocation allocation = get_allocation();
    const double scale_x = (double)allocation.get_width() / m_scale;
    const double scale_y = (double)allocation.get_height() / m_scale;
    auto refStyleContext = get_style_context();

    seekbar_height = 50;
    seekbar_width  = 475;
    seekbar_x = 10;
    seekbar_y = 100;

    refStyleContext->render_background(cr, allocation.get_x(), allocation.get_y(), allocation.get_width(), allocation.get_height());

    const auto state = refStyleContext->get_state();
    Gdk::Cairo::set_source_rgba(cr, refStyleContext->get_color(state));
    cr->rectangle(seekbar_x*scale_x, seekbar_y*scale_y, seekbar_width*scale_x, seekbar_height*scale_y);
    cr->stroke();
    
    return true;
}

