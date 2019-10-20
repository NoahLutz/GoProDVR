#ifndef SEEK_BAR_H
#define SEEK_BAR_H

#include <iostream>
#include <gtkmm/widget.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/styleproperty.h>
#include <gdkmm/general.h>


class SeekBar : public Gtk::Widget
{
    public:
        SeekBar();
        virtual ~SeekBar();
    protected:
        //Overrides
        Gtk::SizeRequestMode get_request_mode_vfunc() const override;
        void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override;
        void get_preferred_height_for_width_vfunc(int width, int& minimum_height, int& natural_height) const override;
        void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
        void get_preferred_width_for_height_vfunc(int height, int& minumum_width, int& natural_width) const override;
        void on_size_allocate(Gtk::Allocation& allocation) override;
        void on_map() override;
        void on_unmap() override;
        void on_realize() override;
        void on_unrealize() override;
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

        void on_parsing_error(const Glib::RefPtr<const Gtk::CssSection>& section, const Glib::Error& error);
        
        Gtk::StyleProperty<int> m_scale_prop;
        Glib::RefPtr<Gdk::Window> m_refGdkWindow;
        Glib::RefPtr<Gtk::CssProvider> m_refCssProvider;

        int m_scale;

    private:
        int seekbar_height;
        int seekbar_width;
        int seekbar_x;
        int seekbar_y;
        int scrubber_height;
        int scrubber_width;
        int scrubber_x;
        int scrubber_y;

};

#endif
